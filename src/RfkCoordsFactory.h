#ifndef RFK_COORDS_FACTORY_H
#define RFK_COORDS_FACTORY_H 1

#include "RfkCoords.h"

/**
 * A factory to produce random coordinates.
 */
class RfkCoordsFactory: public QObject {

  Q_OBJECT

 public:
  /**
   * Constructs the factory.
   *
   * \param arena_width  The width of the arena.
   * \param arena_height  The height of the arena.
   */
  RfkCoordsFactory(int arena_width, int arena_height);

  /**
   * Returns a random position.  The X and Y coordinates
   * of the result will both be zero or above, and will
   * both be less than the arena_width and arena_height
   * parameters to the constructor, respectively.
   *
   * \result  A new random position.
   *
   * \bug What should we do when all positions are exhausted?
   */
  RfkCoords random_position();

 private:
  /**
   * A local copy of the arena's width.
   */
  int m_width;

  /**
   * A local copy of the arena's height.
   */
  int m_height;

  /**
   * All the coordinates which have been previously supplied,
   * so we know we're not producing the same result twice.
   */
  QList<RfkCoords> m_existing;

};

#endif
