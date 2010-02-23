#include "RfkWindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

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
  QPushButton *play = new QPushButton("Play");

  buttonlayout->addWidget(help);
  buttonlayout->addWidget(demo);
  buttonlayout->addWidget(play);
  buttons->setLayout(buttonlayout);

  QWidget *infobox = new QWidget;
  QHBoxLayout *infobox_layout = new QHBoxLayout;
  QLabel *banner = new QLabel(
    "In this game, you are robot (#). "
    "Your job is to find kitten. This task is complicated "
    "by the existence of various things which are not kitten. "
    "Robot must touch items to determine if they are kitten or "
    "not. The game ends when robotfindskitten. You may move "
    "robot about by tapping on any side of the screen, or with the "
    "arrow keys.");

  banner->setWordWrap(true);
  infobox_layout->addWidget(banner);
  infobox->setLayout(infobox_layout);

  QWidget *front_screen = new QWidget;
  QVBoxLayout *front_screen_layout = new QVBoxLayout;

  front_screen_layout->addWidget(infobox);
  front_screen_layout->addWidget(buttons);
  front_screen->setLayout(front_screen_layout);

  return front_screen;
}
