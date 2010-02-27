#include "RfkFinale.h"
#include <QGraphicsPixmapItem>
#include <QDebug>

const int move_dx = 3;

RfkFinale::RfkFinale(QWidget *parent):
  QGraphicsView(parent)
{
  m_robot = m_scene.addPixmap(QPixmap(":/resources/robot.png"));
  m_kitten = m_scene.addPixmap(QPixmap(":/resources/kitten.png"));
  m_love = m_scene.addPixmap(QPixmap(":/resources/love.png"));

  this->setScene(&m_scene);
  this->hideEverything();
}

void RfkFinale::arrangeForStart() {
  int parent_width = this->parentWidget()->width();
  int start_position = (parent_width/2)-m_kitten->pixmap().width();

  this->centerOn(0, 0);

  m_robot->setPos((-start_position) - m_robot->pixmap().width(),
		  -m_robot->pixmap().height()/2);
  m_kitten->setPos(start_position,
		   -m_kitten->pixmap().height()/2);

  m_robot->show();
  m_kitten->show();
  m_love->hide();
}

void RfkFinale::hideEverything() {
  m_robot->hide();
  m_kitten->hide();
  m_love->hide();
}

void RfkFinale::focusInEvent(QFocusEvent* event) {
  this->m_phase = 1;
  this->arrangeForStart();
  this->startTimer(10);
}

void RfkFinale::timerEvent(QTimerEvent *event) {

  switch (m_phase) {
  case 1:
    move_together();
    break;
  case 2:
    grow_love();
    break;
  case 3:
    vibrate();
    this->killTimer(event->timerId());
    this->startTimer(2000);
    m_phase = 4;
    break;
  case 4:
    this->killTimer(event->timerId());
    emit finished();
    this->hideEverything();
    break;
  }

}

void RfkFinale::move_together() {
  QPointF robotPos = m_robot->scenePos();
  QPointF kittenPos = m_kitten->scenePos();

  if (kittenPos.x()-move_dx < m_love->pixmap().width()/2) {

    m_love->setPos(0, 0);
    m_love->scale(0.1, 0.1);
    this->centre_love();
    m_love->show();
    m_phase = 2;

  } else {
    m_robot->setPos(robotPos.x() + move_dx, robotPos.y());
    m_kitten->setPos(kittenPos.x() - move_dx, kittenPos.y());
  }
}

void RfkFinale::grow_love() {
  if (m_love->matrix().m11() >= 0.95) {
    m_phase = 3;
  } else {
    m_love->scale(1.05, 1.05);
    centre_love();
  }
}

void RfkFinale::centre_love() {
  m_love->setPos(
		    -(m_love->pixmap().width()*m_love->matrix().m11())/2,
		    -(m_love->pixmap().height()*m_love->matrix().m22())/2
		    );
}

void RfkFinale::vibrate() {
  qDebug() << "(vibrate)";
}
