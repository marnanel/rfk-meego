#include "RfkController.h"
#include "RfkCoords.h"
#include "RfkItemModel.h"
#include <QDebug>

RfkController::RfkController() {

  qDebug() << "Board created:";

  this->dump_board();

}

void RfkController::move(RfkDirection direction) {
  qDebug () << "Move.";

  RfkCoords robot = m_board.robot_position();
  RfkCoords entered = robot.move(direction, &m_board);
  RfkItemModel *touched = m_board.at(entered);

  if (touched->is_wall()) {
    /* nothing */
  } else if (touched->is_space()) {
    m_board.move_robot(entered);
  } else {
    qDebug() << touched->message();
  }

  this->dump_board();
}

/* temporary */
void RfkController::dump_board() {
  for (int y=-2; y<20; y++) {
    QString line;

    for (int x=-2; x<35; x++) {
      RfkCoords position(x, y);

      if (m_board.robot_position() == position) {
	line += "#";
      } else {
	RfkItemModel *something = m_board.at(position);
	line += something->asChar();
      }
    }

    qDebug() << line;
  }
}

void RfkController::populate(RfkView *view) {
  view->populate(m_board);
}
