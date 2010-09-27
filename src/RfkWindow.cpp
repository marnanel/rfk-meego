#include "RfkWindow.h"
#include "RfkFinale.h"
#include "RfkHelp.h"
#include "RfkProportionalLayout.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include <QDebug>

RfkWindow::RfkWindow() {

#ifdef Q_WS_HILDON
  // Under Maemo, this is a stacked window.
  this->setAttribute(Qt::WA_Maemo5StackedWindow);
#endif

  this->insertWidget(0, this->prepare_front_screen());

  m_view = new RfkView;
  this->insertWidget(1, m_view);

  RfkFinale *finale = new RfkFinale(this);
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

#if 0
  /* The front screen */

  QWidget *buttons = new QWidget;
  QHBoxLayout *buttonlayout = new QHBoxLayout;

  QPushButton *help = new QPushButton("Help");
  QPushButton *demo = new QPushButton("Demo");
  QPushButton *play = new QPushButton("Play");

  QObject::connect(help,
		   SIGNAL(clicked()),
		   this,
		   SLOT(showHelp()) );
		   
  QObject::connect(play,
		   SIGNAL(clicked()),
		   this,
		   SLOT(play_game()) );

  QObject::connect(demo,
		   SIGNAL(clicked()),
		   this,
		   SLOT(playDemo()) );

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
#else

  QLabel *backdrop = new QLabel;
  QWidget *front_screen = new QWidget;
  ProportionalLayout *layout = new ProportionalLayout;
  QLabel *banner = new QLabel(
    "In this game, you are robot (#).  "
    "Your job is to find kitten.  This task is complicated "
    "by the existence of various things which are not kitten.  "
    "Robot must touch items to determine if they are kitten or "
    "not.  The game ends when robotfindskitten.  You may move "
    "robot about by tapping on any side of the screen, or with the "
    "arrow keys.");

  QPushButton *help = new QPushButton("Help");
  QPushButton *demo = new QPushButton("Demo");
  QPushButton *play = new QPushButton("Play");

  QObject::connect(help,
		   SIGNAL(clicked()),
		   this,
		   SLOT(showHelp()) );
		   
  QObject::connect(play,
		   SIGNAL(clicked()),
		   this,
		   SLOT(play_game()) );

  QObject::connect(demo,
		   SIGNAL(clicked()),
		   this,
		   SLOT(playDemo()) );

  backdrop->setPixmap(QPixmap(":/resources/title.png"));
  backdrop->setScaledContents(true);
  banner->setWordWrap(true);

  layout->addItem(new QWidgetItem(backdrop),
		  0.0, 0.0, 1.0, 1.0);
  layout->addItem(new QWidgetItem(banner),
		  0.35, 0.2, 0.65, 0.3);
  layout->addItem(new QWidgetItem(play),
		  0.65, 0.5, 0.35, 0.15);
  layout->addItem(new QWidgetItem(help),
		  0.65, 0.67, 0.35, 0.15);
  layout->addItem(new QWidgetItem(demo),
		  0.65, 0.84, 0.35, 0.15);

  front_screen->setLayout(layout);

#endif


  return front_screen;
}

void RfkWindow::restart() {
  this->setCurrentIndex(0);
}

void RfkWindow::play_game() {
  this->setCurrentIndex(1);
}

void RfkWindow::playDemo() {
  this->setCurrentIndex(1);
  emit startDemo();
}

void RfkWindow::showHelp() {
  RfkHelp *help = new RfkHelp();
  help->show();
}

void RfkWindow::gameWon() {
  this->setCurrentIndex(2);
}

void RfkWindow::keyPressEvent(QKeyEvent * event) {
  /* something */
}
