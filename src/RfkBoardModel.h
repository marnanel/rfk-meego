#ifndef RFK_BOARD_MODEL_H
#define RFK_BOARD_MODEL_H 1

#include <QObject>
#include <QHash>
#include "RfkCoords.h"
#include "RfkItemModel.h"
#include "RfkDescriptions.h"

class RfkBoardModel: public QObject {

 public:
  RfkBoardModel();

  void dump();

  RfkCoords robot_position();

  RfkItemModel* at(RfkCoords position);

 private:
  RfkDescriptions m_descriptions;
  RfkCoords m_robot;
  RfkCoords m_kitten;
  RfkItemModel *m_wall;
  RfkItemModel *m_space;
  QList<RfkItemModel*> m_items;
  QHash<RfkCoords, RfkItemModel*> m_layout;
};

#endif
