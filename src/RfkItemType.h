#ifndef RFK_ITEM_TYPE_H
#define RFK_ITEM_TYPE_H 1

/**
 * Enum representing the types of items in the arena
 * (and out of it).
 */
typedef enum _RfkItemType {
  /**
   * robot.
   */
  RFK_ITEM_TYPE_ROBOT,
  /**
   * kitten.
   */
  RFK_ITEM_TYPE_KITTEN,
  /**
   * A non-kitten item.
   */
  RFK_ITEM_TYPE_NON_KITTEN_ITEM,
  /**
   * A space with nothing in it.
   */
  RFK_ITEM_TYPE_SPACE,
  /**
   * A wall (outside the edge of the arena).
   */
  RFK_ITEM_TYPE_WALL
} RfkItemType;

#endif
