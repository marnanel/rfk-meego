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

RfkCoords RfkCoords::move(RfkDirection whither,
			  RfkBoardModel *board) {
  int newX = first;
  int newY = second;

  switch (whither) {

  case RFK_DIRECTION_NONE:
    /* nothing */
    break;

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
    if (board) {
      RfkDirection candidate;
      const int compass_size = 8;
      const RfkDirection directions[compass_size] = {
	RFK_DIRECTION_NORTH,
	RFK_DIRECTION_NORTHEAST,
	RFK_DIRECTION_EAST,
	RFK_DIRECTION_SOUTHEAST,
	RFK_DIRECTION_SOUTH,
	RFK_DIRECTION_SOUTHWEST,
	RFK_DIRECTION_WEST,
	RFK_DIRECTION_NORTHWEST
      };
      RfkCoords result;

      do {
	candidate = directions[qrand()%compass_size];
	result = this->move(candidate);
      } while (board->at(result)->type()!=RFK_ITEM_TYPE_SPACE);

      return result;
    }
    break;

  case RFK_DIRECTION_DEMO:
    /* not handling this yet */
    break;
  }

  return RfkCoords(newX, newY);
}

float RfkCoords::distance(RfkCoords &other) {
  /* stub */
  return 0.0;
}

RfkDirection RfkCoords::bearing(RfkCoords &other) {
  /* stub */
  return RFK_DIRECTION_NONE;
}
