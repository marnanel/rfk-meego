#ifndef RFK_WINDOW
#define RFK_WINDOW 1

#include <QStackedWidget>
#include "RfkView.h"

class RfkWindow: public QStackedWidget {
 Q_OBJECT

 public:
  RfkWindow();

  RfkView* view();

 protected:
  void keyPressEvent(QKeyEvent *event);

 public slots:
  void play_game();
  void gameWon();
  void restart();

 private:
  RfkView *m_view;
  QWidget* prepare_front_screen();
};

#endif
