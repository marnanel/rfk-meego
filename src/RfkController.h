#ifndef RFK_CONTROLLER
#define RFK_CONTROLLER 1

#include "RfkBoardModel.h"
#include "RfkDirection.h"

class RfkController: public QObject {
 public:
  RfkController();

  void move(RfkDirection direction);

 private:
  RfkBoardModel m_board;
  void dump_board();
};

#endif
