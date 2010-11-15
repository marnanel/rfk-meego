#include "RfkFinale.h"
#include "RfkVibrate.h"
#include <QDebug>
#include <QPainter>

const int move_dx = 3;

RfkFinale::RfkFinale(QWidget *parent):
  QWidget(parent),
  m_robot(":/resources/robot.png"),
  m_kitten(":/resources/kitten.png"),
  m_love(":/resources/love.png")
{
  // nothing
}

void RfkFinale::focusInEvent(QFocusEvent* event) {

  Q_UNUSED(event);

  this->m_robotX = 0;
  this->m_loveSize = 0;
  this->startTimer(10);
}

void RfkFinale::timerEvent(QTimerEvent *event) {

  // We could cache the stopping position,
  // but it might change during the animation
  // (for example, if they rotate the device).

  int robotStop = (this->width()-m_love.width())/2 - m_kitten.width();

  if (m_robotX < robotStop) {
    m_robotX++;
    m_loveSize = 0;
  } else if (m_robotX > robotStop) {
    // just in case
    m_robotX--;
    m_loveSize = 0;
  } else {
    // robot and kitten are in their proper places:
    // time enough for love

    if (m_loveSize < m_love.width()) {
      m_loveSize++;

      if (m_loveSize >= m_love.width()) {
	RfkVibrate vibration;

	vibration.vibrate();

	this->killTimer(event->timerId());
	this->startTimer(2000);
      }

    } else {
      this->killTimer(event->timerId());
      emit finished();
    }
  }

  update();
}

void RfkFinale::paintEvent(QPaintEvent *event) {

  Q_UNUSED(event);

  QPainter painter(this);
  QBrush black(Qt::SolidPattern);

  int y = (this->height()-m_love.height())/2;

  painter.setBrush(black);
  painter.drawRect(0, 0, this->width(), this->height());

  painter.drawPixmap(m_robotX+ (this->m_kitten.width() - this->m_robot.width()),
		     y, m_robot);
  painter.drawPixmap(this->width()-(m_robotX+m_kitten.width()),
		     y, m_kitten);

  if (m_loveSize > 0) {
    painter.drawPixmap((this->width()-m_loveSize)/2,
		       (y+m_love.height()/2)-m_loveSize/2,
		       m_loveSize,
		       m_loveSize,
		       m_love);
  }
}
