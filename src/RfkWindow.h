#ifndef RFK_WINDOW
#define RFK_WINDOW 1

#include <QStackedWidget>
#include "RfkView.h"

class RfkWindow: public QStackedWidget {
 Q_OBJECT

 public:
  RfkWindow();

  RfkView* view();

  void show_message(QString message);

 public slots:
  void play_game();

 private:
  RfkView *m_view;
  QWidget* prepare_front_screen();
};

#endif
