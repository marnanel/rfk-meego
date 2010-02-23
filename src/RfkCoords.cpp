#include <QDebug>
#include "RfkCoords.h"
#include "RfkBoardModel.h"

RfkCoords::RfkCoords() {
  first = 0;
  second = 0;
}

RfkCoords::RfkCoords(int x, int y) {
  first = x;
  second = y;
}

int RfkCoords::x() {
  return first;
}

int RfkCoords::y() {
  return second;
}

void RfkCoords::dump() {
  qDebug() << "(" << first << "," << second << ")";
}

RfkCoords RfkCoords::move(RfkDirection whither,
			  RfkBoardModel *board) {
  int newX = first;
  int newY = second;

  switch (whither) {
  case RFK_DIRECTION_NORTH:
    newY--;
    break;

  case RFK_DIRECTION_NORTHEAST:
    newX++;
    newY--;
    break;

  case RFK_DIRECTION_EAST:
    newX++;
    break;

  case RFK_DIRECTION_SOUTHEAST:
    newX++;
    newY++;
    break;

  case RFK_DIRECTION_SOUTH:
    newY++;
    break;

  case RFK_DIRECTION_SOUTHWEST:
    newX--;
    newY++;
    break;

  case RFK_DIRECTION_WEST:
    newX--;
    break;

  case RFK_DIRECTION_NORTHWEST:
    newX--;
    newY--;
    break;

  case RFK_DIRECTION_RANDOM:
  case RFK_DIRECTION_DEMO:
    /* not handling these yet */
    break;
  }

  return RfkCoords(newX, newY);
}
