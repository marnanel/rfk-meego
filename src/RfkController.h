#ifndef RFK_CONTROLLER
#define RFK_CONTROLLER 1

#include "RfkBoardModel.h"

class RfkController: public QObject {
 public:
  RfkController();

 private:
  RfkBoardModel m_board;
};

#endif
