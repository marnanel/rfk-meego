#include <QDebug>
#include "RfkCoords.h"

RfkCoords::RfkCoords() {
  first = 0;
  second = 0;
}

RfkCoords::RfkCoords(int x, int y) {
  first = x;
  second = y;
}

const int RfkCoords::x() {
  return first;
}

const int RfkCoords::y() {
  return second;
}

void RfkCoords::dump() {
  qDebug() << "(" << first << "," << second << ")";
}

RfkCoords RfkCoords::move(RfkDirection whither) {
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
    newY--;
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
