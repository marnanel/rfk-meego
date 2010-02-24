#ifndef RFK_VIEW
#define RFK_VIEW 1

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QKeyEvent>
#include <QHash>
#include "RfkBoardModel.h"

class RfkView: public QWidget {

  Q_OBJECT

 public:
  RfkView();

  void populate(RfkBoardModel &board);

 signals:
  void movementRequest(RfkDirection direction);

 protected:
  void keyPressEvent(QKeyEvent * event);

 private:
  QHash<int, RfkDirection> m_keymap;

  QLabel* random_character();
  QGridLayout *m_grid;
};

#endif
