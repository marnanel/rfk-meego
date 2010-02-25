#include "RfkWindow.h"
#include "RfkFinale.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>

RfkWindow::RfkWindow() {

  this->insertWidget(0, this->prepare_front_screen());

  m_view = new RfkView;
  this->insertWidget(1, m_view);

  RfkFinale *finale = new RfkFinale;
  this->insertWidget(2, finale);

  QObject::connect(finale,
		   SIGNAL(finished()),
		   this,
		   SLOT(restart()) );
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

  QObject::connect(play,
		   SIGNAL(clicked()),
		   this,
		   SLOT(play_game()) );

  buttonlayout->addWidget(help);
  buttonlayout->addWidget(demo);
  buttonlayout->addWidget(play);
  buttons->setLayout(buttonlayout);

  QWidget *infobox = new QWidget;
  QHBoxLayout *infobox_layout = new QHBoxLayout;
  QLabel *robot = new QLabel();
  QLabel *banner = new QLabel(
    "In this game, you are robot (#). "
    "Your job is to find kitten. This task is complicated "
    "by the existence of various things which are not kitten. "
    "Robot must touch items to determine if they are kitten or "
    "not. The game ends when robotfindskitten. You may move "
    "robot about by tapping on any side of the screen, or with the "
    "arrow keys.");
  QLabel *kitten = new QLabel();

  robot->setPixmap(QPixmap(":/resources/robot.png"));
  banner->setWordWrap(true);
  kitten->setPixmap(QPixmap(":/resources/kitten.png"));

  infobox_layout->addWidget(robot);
  infobox_layout->addWidget(banner);
  infobox_layout->addWidget(kitten);
  infobox->setLayout(infobox_layout);

  QWidget *front_screen = new QWidget;
  QVBoxLayout *front_screen_layout = new QVBoxLayout;

  front_screen_layout->addWidget(infobox);
  front_screen_layout->addWidget(buttons);
  front_screen->setLayout(front_screen_layout);

  return front_screen;
}

void RfkWindow::restart() {
  this->setCurrentIndex(0);
}

void RfkWindow::play_game() {
  this->setCurrentIndex(1);
}

void RfkWindow::gameWon() {
  this->setCurrentIndex(2);
}

void RfkWindow::keyPressEvent(QKeyEvent * event) {
  /* something */
}
