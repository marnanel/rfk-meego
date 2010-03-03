#include "RfkBoardModel.h"
#include "RfkCoordsFactory.h"
#include <QDebug>

const int number_of_non_kitten_items = 17;
const int board_width = 30;
const int board_height = 17;

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
    return m_wall;
  } else {
    return m_layout.value(position, m_space);
  }
}

RfkCoords RfkBoardModel::southeast_corner() {
  return RfkCoords(board_width-1, board_height-1);
}

void RfkBoardModel::itemVisited(RfkItemModel *which) {
  m_visited.append(which);
}

RfkCoords RfkBoardModel::interestingPosition() {

  /* Is it cached? */
  if (m_interesting) {
    return *m_interesting;
  }

  /* stub */
  m_interesting = new RfkCoords(this->southeast_corner());

  return *m_interesting;
}
