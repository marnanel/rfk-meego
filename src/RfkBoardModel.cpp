#include "RfkBoardModel.h"
#include "RfkCoordsFactory.h"
#include <cmath>
#include <QDebug>

const int number_of_non_kitten_items = 17;
const int board_width = 30;
const int board_height = 16;

RfkBoardModel::RfkBoardModel() {

  RfkCoordsFactory factory (board_width, board_height);
  RfkDescriptions descriptions;
  RfkItemModel *kitten =
    new RfkItemModel(RFK_ITEM_TYPE_KITTEN,
		     "You found kitten!  Way to go, robot!");

  m_wall = new RfkItemModel(RFK_ITEM_TYPE_WALL);
  m_space = new RfkItemModel(RFK_ITEM_TYPE_SPACE);
  m_interesting = NULL;

  m_robot = factory.random_position();

  m_layout[factory.random_position()] = kitten;

  for (int i=0; i < number_of_non_kitten_items; i++) {
    m_layout[factory.random_position()] =
      new RfkItemModel(RFK_ITEM_TYPE_NON_KITTEN_ITEM,
		       descriptions.description());
  }
}

void RfkBoardModel::dump()
{
  /* currently a stub; may remove this */
}

RfkCoords RfkBoardModel::robot_position() {
  return m_robot;
}

void RfkBoardModel::robotMoved(RfkCoords where) {
  m_robot = where;
}

RfkItemModel* RfkBoardModel::at(RfkCoords position) {

  if (position.x()<0 || position.y()<0 ||
      position.x()>=board_width || position.y()>=board_height) {

    // Off the edge of the arena: return the wall.

    return m_wall;

  } else {

    // Look it up in the list of items.
    // If it's not there, return the space.

    return m_layout.value(position, m_space);
  }
}

RfkCoords RfkBoardModel::southeast_corner() {
  return RfkCoords(board_width-1, board_height-1);
}

void RfkBoardModel::itemVisited(RfkItemModel *which) {

  // Record that we've visited this item.

  m_visited.append(which);

  // If this is something we were moving towards,
  // we should stop now.

  if (m_interesting &&
      m_layout[*m_interesting]==which) {
    delete m_interesting;
    m_interesting = NULL;
  }
}

RfkCoords RfkBoardModel::interestingPosition() {

  // Is it cached?

  if (m_interesting) {
    return *m_interesting; // Yes, so just return that.
  }

  RfkCoords closest;
  float closestDistance = HUGE_VAL;
  QList<RfkCoords> positions = m_layout.keys();

  // Now run over all the items, and find the closest
  // item we haven't visited.

  for (QList<RfkCoords>::iterator i = positions.begin(); i != positions.end(); i++) {

    // Don't consider items we've already visited.

    if (m_visited.contains(m_layout[*i])) {
      continue;
    }

    float distance = m_robot.distance(*i);
    
    if (distance < closestDistance) {
      // Best candidate so far.
      closest = *i;
      closestDistance = distance;
    }
  }

  m_interesting = new RfkCoords(closest);

  return *m_interesting;
}
