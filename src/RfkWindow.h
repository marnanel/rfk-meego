#ifndef RFK_WINDOW
#define RFK_WINDOW 1

#include <QStackedWidget>
#include "RfkView.h"

class RfkWindow: public QStackedWidget {
 public:
  RfkWindow();

  RfkView* view();

 private:
  RfkView *m_view;
  QWidget* prepare_front_screen();
};

#endif
