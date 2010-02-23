#ifndef RFK_COORDS_H
#define RFK_COORDS_H 1

#include "RfkDirection.h"

#include <QObject>
#include <QDataStream>
#include <QPair>

class RfkBoardModel;

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
  int x();

  /**
   * Returns the Y coordinate.
   */
  int y();

  RfkCoords move(RfkDirection whither,
		 RfkBoardModel *board=NULL);

  void dump();
};

#endif
