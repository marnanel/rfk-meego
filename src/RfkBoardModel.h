#ifndef RFK_BOARD_MODEL_H
#define RFK_BOARD_MODEL_H 1

#include <QObject>
#include <QHash>
#include "RfkCoords.h"
#include "RfkItemModel.h"
#include "RfkDescriptions.h"

/**
 * A model of the board (and the game as a whole).
 */
class RfkBoardModel: public QObject {

  Q_OBJECT

 public:
  /**
   * Constructor.
   */
  RfkBoardModel();

  /**
   * Dumps the state of the board; will be removed.
   *
   * \bug Remove this.
   */
  void dump();

  /**
   * Returns robot's position.
   *
   * \result Robot's position.
   */
  RfkCoords robot_position();

  /**
   * Returns the item at the given position.  The returned item
   * is owned by the board model and should not be destroyed or
   * modified.  If the position is off the edge of the arena,
   * the returned item will be a wall.  If it is robot or a space,
   * the returned item will be a space.
   *
   * \param position  An arbitrary position
   * \return  The item at that position.
   *
   * \bug If they ask for the position where robot is, we should
   * probably say that robot is there, rather than returning a space.
   */
  RfkItemModel* at(RfkCoords position);

  /**
   * The southeasternmost corner of the arena.  Since the arena is
   * rectangular, and the northwesternmost corner is always at (0, 0),
   * we can use this to find out everything about the borders.
   *
   * \return The address of the southeasternmost corner.
   */
  RfkCoords southeast_corner();

  /**
   * The position of something interesting that robot can move
   * towards in the demo mode.  This will always be the position of
   * an item (possibly kitten) which has not been previously
   * visited.
   *
   * \return The position of something interesting.
   */
  RfkCoords interestingPosition();

  public slots:
  /**
   * Received when robot moves to a new position.
   *
   * \param where  The new position.
   */
  void robotMoved(RfkCoords where);

  /**
   * Received when an item is visited.
   *
   * \param which  The visted item.
   */
  void itemVisited(RfkItemModel *which);

 private:
  /**
   * The position of robot.
   */
  RfkCoords m_robot;

  /**
   * An item representing any wall.  Returned when a position
   * is requested which is off the edge of the arena.
   */
  RfkItemModel *m_wall;

  /**
   * An item representing any space.  Returned when a position
   * is requested which is in the arena, but we have no record
   * of an item being there.
   */
  RfkItemModel *m_space;

  /**
   * A mapping of coordinates to known items.
   */
  QHash<RfkCoords, RfkItemModel*> m_layout;

  /**
   * If we're moving towards an interesting position, this
   * holds that position.  Otherwise it's NULL, and we will
   * have to work out a position if necessary.
   *
   * (If we didn't allow this to be NULL for unknown,
   * and we automatically rescanned when the position became
   * visited, then the system would lock up when kitten was
   * the last-visted item.)
   */
  RfkCoords *m_interesting;

  /**
   * A list of items we know to have been visited.
   */
  QList<RfkItemModel*> m_visited;
};

#endif
