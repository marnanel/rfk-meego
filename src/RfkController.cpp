#include "RfkController.h"
#include "RfkCoords.h"
#include "RfkItemModel.h"
#include <QDebug>

RfkController::RfkController(RfkBoardModel *board):
  m_board(board) {
  /* ... */
}

void RfkController::move(RfkDirection direction, bool running) {

  if (running &&
      direction != RFK_DIRECTION_NONE &&
      direction != RFK_DIRECTION_DEMO &&
      direction != RFK_DIRECTION_RANDOM) {
    qDebug() << "This would be running.";
  } else {
    this->moveOneStep(direction);
  }
}

bool RfkController::moveOneStep(RfkDirection direction) {

  RfkCoords robot = m_board->robot_position();
  RfkCoords entered = robot.move(direction, m_board);
  RfkItemModel *touched = m_board->at(entered);

  switch (touched->type()) {

  case RFK_ITEM_TYPE_WALL:
    return false;

  case RFK_ITEM_TYPE_SPACE:
    emit robotMoved(entered);
    return true;

  default:
    emit somethingDiscovered(touched->message());

    if (touched->type() == RFK_ITEM_TYPE_KITTEN) {
      emit discoveredKitten();
    }
    return false;
  }
}
