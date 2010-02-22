#ifndef RFK_ITEM_MODEL_H
#define RFK_ITEM_MODEL_H 1

#include <QObject>
#include "RfkCoords.h"

class RfkItemModel: public QObject {

 public:
  RfkItemModel(QString what);

  RfkItemModel(bool wall);

  void dump();

  QString asChar();

  bool is_wall();
  bool is_space();

 private:
  QString m_message;
  bool m_is_wall;
  bool m_is_space;
};

#endif
