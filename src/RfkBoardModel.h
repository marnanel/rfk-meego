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
  RfkCoords m_robot;
  RfkItemModel *m_wall;
  RfkItemModel *m_space;
  QHash<RfkCoords, RfkItemModel*> m_layout;
};

#endif
