#include "RfkFinale.h"

RfkFinale::RfkFinale():
  QGraphicsView()
{
  m_robot = m_scene.addPixmap(QPixmap(":/resources/robot.png"));
  m_kitten = m_scene.addPixmap(QPixmap(":/resources/kitten.png"));
  m_love = m_scene.addPixmap(QPixmap(":/resources/love.png"));

  this->setScene(&m_scene);
}

void RfkFinale::play() {
  /* ... */
}
