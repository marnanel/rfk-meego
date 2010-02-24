#include "RfkController.h"
#include "RfkCoords.h"
#include "RfkItemModel.h"
#include <QDebug>

RfkController::RfkController(RfkBoardModel *board):
  m_board(board) {
  /* ... */
}

void RfkController::move(RfkDirection direction) {

  RfkCoords robot = m_board->robot_position();
  RfkCoords entered = robot.move(direction, m_board);
  RfkItemModel *touched = m_board->at(entered);

  if (touched->is_wall()) {
    /* nothing */
  } else if (touched->is_space()) {
    emit robotMoved(entered);
  } else {
    emit somethingDiscovered(touched->message());
  }
}
