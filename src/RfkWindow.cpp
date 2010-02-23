#include "RfkWindow.h"
#include <QHBoxLayout>
#include <QPushButton>

RfkWindow::RfkWindow() {

  this->insertWidget(0, this->prepare_front_screen());

  /* The board view itself */

  m_view = new RfkView;
  this->insertWidget(1, m_view);
}

RfkView* RfkWindow::view() {
  return m_view;
}

QWidget* RfkWindow::prepare_front_screen() {
  /* The front screen */

  QWidget *buttons = new QWidget;
  QHBoxLayout *buttonlayout = new QHBoxLayout;

  QPushButton *help = new QPushButton("Help");
  QPushButton *demo = new QPushButton("Demo");
  QPushButton *quit = new QPushButton("Quit");

  buttonlayout->addWidget(help);
  buttonlayout->addWidget(demo);
  buttonlayout->addWidget(quit);
  buttons->setLayout(buttonlayout);

  return buttons;
}
