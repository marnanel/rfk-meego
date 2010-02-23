#ifndef RFK_VIEW
#define RFK_VIEW 1

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QKeyEvent>
#include "RfkBoardModel.h"

class RfkView: public QWidget {
 public:
  RfkView();

  void populate(RfkBoardModel &board);

 protected:
  void keyPressEvent(QKeyEvent * event);

 private:
  QLabel* random_character();
  QGridLayout *m_grid;
};

#endif
