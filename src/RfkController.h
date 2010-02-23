#ifndef RFK_CONTROLLER
#define RFK_CONTROLLER 1

#include "RfkBoardModel.h"
#include "RfkDirection.h"
#include "RfkView.h"

class RfkController: public QObject {
 public:
  RfkController();

  void move(RfkDirection direction);

  void populate(RfkView *view);

 private:
  RfkBoardModel m_board;
  void dump_board();
};

#endif
