#ifndef RFK_ITEM_MODEL_H
#define RFK_ITEM_MODEL_H 1

#include <QObject>
#include "RfkCoords.h"

class RfkItemModel: public QObject {

 public:
  RfkItemModel(QString what);
  RfkItemModel();

  void dump();

  QString asChar();

  QString message();

  bool is_wall();
  bool is_space();
  bool is_kitten();

  void set_is_wall(bool whether);
  void set_is_space(bool whether);
  void set_is_kitten(bool whether);

 private:
  QString m_message;
  bool m_is_wall;
  bool m_is_space;
  bool m_is_kitten;
};

#endif
