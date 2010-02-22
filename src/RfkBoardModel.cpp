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
    new RfkItemModel("You found kitten!  Way to go, robot!");

  m_wall = new RfkItemModel();
  m_space = new RfkItemModel();

  m_wall->set_is_wall(true);
  m_space->set_is_space(true);

  m_robot = factory.random_position();

  kitten->set_is_kitten(true);
  m_layout[factory.random_position()] = kitten;

  for (int i=0; i < number_of_non_kitten_items; i++) {
    m_layout[factory.random_position()] =
      new RfkItemModel(descriptions.description());
  }
}

void RfkBoardModel::dump()
{
  /* currently a stub; may remove this */
}

RfkCoords RfkBoardModel::robot_position() {
  return m_robot;
}

RfkItemModel* RfkBoardModel::at(RfkCoords position) {
  if (position.x()<0 || position.y()<0 ||
      position.x()>=board_width || position.y()>=board_height) {
    return m_wall;
  } else {
    return m_layout.value(position, m_space);
  }
}
