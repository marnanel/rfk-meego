#ifndef RFK_BOARD_MODEL_H
#define RFK_BOARD_MODEL_H 1

#include <QObject>
#include "RfkCoords.h"
#include "RfkItemModel.h"
#include "RfkDescriptions.h"

class RfkBoardModel: public QObject {

 public:
  RfkBoardModel();

  void dump();

  RfkCoords robot_position();

 private:
  RfkDescriptions m_descriptions;
  RfkCoords m_robot;
  RfkCoords m_kitten;
  QList<RfkItemModel*> m_items;
};

#endif
