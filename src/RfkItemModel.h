#ifndef RFK_ITEM_MODEL_H
#define RFK_ITEM_MODEL_H 1

#include <QObject>
#include "RfkCoords.h"

class RfkItemModel: public QObject {

 public:
  RfkItemModel(RfkCoords where, QString what);

  void dump();

 private:
  RfkCoords m_coords;
  QString m_message;
};

#endif
