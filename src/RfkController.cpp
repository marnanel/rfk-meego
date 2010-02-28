#include "RfkController.h"
#include "RfkCoords.h"
#include "RfkItemModel.h"
#include <QDebug>

RfkController::RfkController(RfkBoardModel *board):
  m_board(board) {
  /* ... */
}

void RfkController::move(RfkDirection direction, bool running) {

  RfkCoords robot = m_board->robot_position();
  RfkCoords entered = robot.move(direction, m_board);
  RfkItemModel *touched = m_board->at(entered);

  if (running) {
    qDebug() << "This would be running.";
  }

  switch (touched->type()) {

  case RFK_ITEM_TYPE_WALL:
    /* nothing */
    break;

  case RFK_ITEM_TYPE_SPACE:
    emit robotMoved(entered);
    break;

  default:
    emit somethingDiscovered(touched->message());

    if (touched->type() == RFK_ITEM_TYPE_KITTEN) {
      emit discoveredKitten();
    }
  }
}
