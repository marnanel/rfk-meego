#ifndef RFK_CONTROLLER
#define RFK_CONTROLLER 1

#include "RfkBoardModel.h"
#include "RfkDirection.h"
#include "RfkView.h"

class RfkController: public QObject {
  Q_OBJECT

 public:
  RfkController(RfkBoardModel *board);

  public slots:
  void move(RfkDirection direction);

 signals:
  void robotMoved(RfkCoords newPlace);
  void somethingDiscovered(QString message);

 private:
  RfkBoardModel *m_board;
  void dump_board();
};

#endif
