#include "RfkController.h"
#include "RfkCoords.h"
#include "RfkItemModel.h"
#include <QDebug>

RfkController::RfkController(RfkBoardModel *board):
  m_board(board),
  m_timerId(0) {
  /* ... */
}

void RfkController::move(RfkDirection direction, bool running) {

  if (running &&
      direction != RFK_DIRECTION_NONE &&
      direction != RFK_DIRECTION_DEMO &&
      direction != RFK_DIRECTION_RANDOM) {

    m_runningDirection = direction;
    m_timerId = this->startTimer(50);

  } else {

    this->stopRunning();
    this->moveOneStep(direction);
  }
}

void RfkController::stopRunning() {
  if (m_timerId) {
    this->killTimer(m_timerId);
    m_timerId = 0;
  }
}

void RfkController::timerEvent(QTimerEvent *event) {
  if (!this->moveOneStep(m_runningDirection)) {
    this->stopRunning();
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
