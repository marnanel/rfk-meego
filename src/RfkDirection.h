#ifndef RFK_DIRECTION_H
#define RFK_DIRECTION_H 1

/**
 * Enum representing the directions robot can move.
 */
typedef enum _RfkDirection {
  /**
   * No movement: the identity transformation.
   */
  RFK_DIRECTION_NONE,
  /**
   * Towards the top of the screen.
   */
  RFK_DIRECTION_NORTH,
  /**
   * Towards the top right of the screen.
   */
  RFK_DIRECTION_NORTHEAST,
  /**
   * Towards the right of the screen.
   */
  RFK_DIRECTION_EAST,
  /**
   * Towards the bottom right of the screen.
   */
  RFK_DIRECTION_SOUTHEAST,
  /**
   * Towards the bottom of the screen.
   */
  RFK_DIRECTION_SOUTH,
  /**
   * Towards the bottom left of the screen.
   */
  RFK_DIRECTION_SOUTHWEST,
  /**
   * Towards the left of the screen.
   */
  RFK_DIRECTION_WEST,
  /**
   * Towards the top left of the screen.
   */
  RFK_DIRECTION_NORTHWEST,
  /**
   * In a random direction, as long as that direction
   * moves into a space (rather than a wall or an item).
   */
  RFK_DIRECTION_RANDOM,
  /**
   * Directly towards the closest item we haven't yet visited,
   * except if that would lead into a different item,
   * when this is the same as RFK_DIRECTION_RANDOM.
   */
  RFK_DIRECTION_DEMO
} RfkDirection;

#endif
