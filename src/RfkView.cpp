#include "RfkView.h"
#include <QGridLayout>
#include <QLabel>
#include <QDebug>
#include <QMessageBox>

RfkView::RfkView(): m_grid(new QGridLayout()) {

  m_grid = new QGridLayout;
  this->setLayout(m_grid);

  /* arrows */
  m_keymap[Qt::Key_Up]       = RFK_DIRECTION_NORTH;
  m_keymap[Qt::Key_PageUp]   = RFK_DIRECTION_NORTHEAST;
  m_keymap[Qt::Key_Right]    = RFK_DIRECTION_EAST;
  m_keymap[Qt::Key_PageDown] = RFK_DIRECTION_SOUTHEAST;
  m_keymap[Qt::Key_Down]     = RFK_DIRECTION_SOUTH;
  m_keymap[Qt::Key_End]      = RFK_DIRECTION_SOUTHWEST;
  m_keymap[Qt::Key_Left]     = RFK_DIRECTION_WEST;
  m_keymap[Qt::Key_Home]     = RFK_DIRECTION_NORTHWEST;

  /* vi / nethack */
  m_keymap[Qt::Key_K]        = RFK_DIRECTION_NORTH;
  m_keymap[Qt::Key_U]        = RFK_DIRECTION_NORTHEAST;
  m_keymap[Qt::Key_L]        = RFK_DIRECTION_EAST;
  m_keymap[Qt::Key_N]        = RFK_DIRECTION_SOUTHEAST;
  m_keymap[Qt::Key_J]        = RFK_DIRECTION_SOUTH;
  m_keymap[Qt::Key_B]        = RFK_DIRECTION_SOUTHWEST;
  m_keymap[Qt::Key_H]        = RFK_DIRECTION_WEST;
  m_keymap[Qt::Key_Y]        = RFK_DIRECTION_NORTHWEST;

  /* other */
  m_keymap[Qt::Key_D]        = RFK_DIRECTION_DEMO;
  m_keymap[Qt::Key_R]        = RFK_DIRECTION_RANDOM;
}

void RfkView::populate(RfkBoardModel *board) {

  RfkCoords southeast = board->southeast_corner();
  m_robot = board->robot_position();

  while (QLayoutItem *child = m_grid->takeAt(0)) {
    child->widget()->deleteLater();
  }

  for (int x=0; x<=southeast.x(); x++) {
    for (int y=0; y<=southeast.y(); y++) {
      RfkCoords position(x,y);
      QLabel *label;

      if (m_robot==position) {
	label = new QLabel("#");
	label->setAlignment(Qt::AlignCenter);
      } else {
	RfkItemModel* item = board->at(position);

	if (item->type() == RFK_ITEM_TYPE_SPACE) {
	  label = new QLabel();
	} else {
	  label = this->random_character();
	}
      }

      m_grid->addWidget(label,
			y, x);
    }
  }
}

QLabel* RfkView::random_character() {

  char symbol = qrand()%('~'-'!') + '!';
  int colour = qrand() % 0xFFFFFF;
  QString text("<span style=\"color:#%2\">%1</span>");

  text = text.arg(symbol).arg(colour, 6, 16);

  QLabel *result = new QLabel();

  result->setAlignment(Qt::AlignCenter);
  result->setText(text);
  result->setTextFormat(Qt::RichText);
  
  return result;
}

void RfkView::keyPressEvent(QKeyEvent * event) {

  if (m_keymap.contains(event->key())) {
    emit movementRequest(m_keymap[event->key()]);
    event->accept();
  } else {
    event->ignore();
  }
}

void RfkView::robotMoved(RfkCoords where) {

  QLayoutItem *robot = m_grid->itemAtPosition(m_robot.y(), m_robot.x());
  QLayoutItem *space = m_grid->itemAtPosition(where.y(), where.x());

  m_grid->removeItem(robot);
  m_grid->removeItem(space);
  m_grid->addItem(space, m_robot.y(), m_robot.x());
  m_grid->addItem(robot, where.y(), where.x());
  
  m_robot = where;
}

void RfkView::showMessage(QString message) {

  /* FIXME Pop up a banner instead under Maemo */

  QMessageBox::warning(this, "robotfindskitten",
		       message,
		       QMessageBox::Ok,
		       QMessageBox::Ok);
}
