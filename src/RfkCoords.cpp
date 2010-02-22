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
