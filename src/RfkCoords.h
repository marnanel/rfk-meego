#ifndef RFK_COORDS_H
#define RFK_COORDS_H 1

#include <QObject>
#include <QDataStream>
#include <QPair>

/**
 * Represents an (x,y) pair of Cartesian coordinates.
 */
class RfkCoords: public QPair<int,int> {

 public:

  RfkCoords();
  RfkCoords(int x, int y);

  /**
   * Returns the X coordinate.
   */
  const int x();

  /**
   * Returns the Y coordinate.
   */
  const int y();

  uint qHash();

  void dump();
};

#endif
