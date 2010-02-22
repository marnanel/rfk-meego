#ifndef RFK_BOARD_MODEL_H
#define RFK_BOARD_MODEL_H 1

#include <QObject>
#include "RfkCoords.h"
#include "RfkItemModel.h"
#include "RfkDescriptions.h"

typedef enum _RfkContent {
  RFK_WALL, /* off the edge of the arena */
  RFK_SPACE,
  RFK_NON_KITTEN_ITEM,
  RFK_KITTEN,
  RFK_ROBOT
} RfkContent;

class RfkBoardModel: public QObject {

 public:
  RfkBoardModel();

  void dump();

  RfkCoords robot_position();

  RfkContent at(RfkCoords position);

 private:
  RfkDescriptions m_descriptions;
  RfkCoords m_robot;
  RfkCoords m_kitten;
  QList<RfkItemModel*> m_items;
};

#endif
