#ifndef RFK_VIEW
#define RFK_VIEW 1

#include <QWidget>
#include "RfkBoardModel.h"

class RfkView: public QWidget {
 public:
  RfkView();

  void populate(RfkBoardModel &board);
};

#endif
