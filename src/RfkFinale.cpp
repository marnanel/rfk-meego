#include "RfkFinale.h"
#include <QGraphicsPixmapItem>
#include <QDebug>

RfkFinale::RfkFinale(QWidget *parent):
  QGraphicsView(parent)
{
  m_robot = m_scene.addPixmap(QPixmap(":/resources/robot.png"));
  m_kitten = m_scene.addPixmap(QPixmap(":/resources/kitten.png"));
  m_love = m_scene.addPixmap(QPixmap(":/resources/love.png"));

  this->setScene(&m_scene);

  int parent_width = this->parentWidget()->width();

  this->centerOn(0, 0);

  m_robot->setPos(-parent_width/2,
		  0);
  m_kitten->setPos(parent_width/2,
		   0);
  m_love->hide();
}

void RfkFinale::focusInEvent(QFocusEvent* event) {

}
