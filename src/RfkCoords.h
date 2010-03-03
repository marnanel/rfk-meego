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

  /**
   * Constructor for the default coordinates.
   * The x and y fields will both be zero.
   */
  RfkCoords();

  /**
   * Constructor for a particular pair of coordinates.
   * \param x  The x coordinate.
   * \param y  The y coordinate.
   */
  RfkCoords(int x, int y);

  /**
   * Returns the X coordinate.
   *
   * \result The X coordinate.
   */
  int x();

  /**
   * Returns the Y coordinate.
   *
   * \result The Y coordinate.
   */
  int y();

  /**
   * Translates this coordinate in a particular direction.
   * Returns the new position; does not affect the original coordinates.
   *
   * \param whither  The direction to move in.
   * \param board    The board on which we are moving.  This is optional;
   *                 it is used only for the "demo" and "random" moves.
   *                 If it is omitted for these moves, the result will
   *                 be equal to the original coordinates.
   * \result         The new position.
   */
  RfkCoords move(RfkDirection whither,
		 RfkBoardModel *board=NULL);

  /**
   * Returns the distance between this RfkCoords and another one.
   *
   * \param other  The other RfkCoords.
   * \return   The distance between the two positions.
   */
  float distance(RfkCoords &other);

  /**
   * Returns the bearing between this RfkCoords and another one.
   *
   * \param other  The other RfkCoords
   * \return       The bearing between this RfkCoords and
   *               the other one.  Will not be RFK_DIRECTION_DEMO
   *               or RFK_DIRECTION_RANDOM.
   */
  RfkDirection bearing(RfkCoords &other);

};

#endif
