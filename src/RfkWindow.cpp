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

  m_blink = new QLabel();
  m_blink->setPixmap(QPixmap(":/resources/blink.png"));
  m_blink->setScaledContents(true);
  m_blink->hide();
  this->startBlinking();

  layout->addItem(new QWidgetItem(backdrop),
		  0.0, 0.0, 1.0, 1.0);
  layout->addItem(new QWidgetItem(m_blink),
		  0.3, 0.7, 0.1, 0.2);
  layout->addItem(new QWidgetItem(banner),
		  0.35, 0.2, 0.65, 0.3);
  layout->addItem(new QWidgetItem(play),
		  0.65, 0.5, 0.35, 0.15);
  layout->addItem(new QWidgetItem(help),
		  0.65, 0.67, 0.35, 0.15);
  layout->addItem(new QWidgetItem(demo),
		  0.65, 0.84, 0.35, 0.15);

  front_screen->setLayout(layout);

  return front_screen;
}

void RfkWindow::restart() {
  this->setCurrentIndex(0);
  this->startBlinking();
}

void RfkWindow::play_game() {
  this->setCurrentIndex(1);
  this->stopBlinking();
}

void RfkWindow::playDemo() {
  this->setCurrentIndex(1);
  this->stopBlinking();
  emit startDemo();
}

void RfkWindow::showHelp() {
  RfkHelp *help = new RfkHelp();
  // don't stop blinking just for that
  help->show();
}

void RfkWindow::gameWon() {
  this->setCurrentIndex(2);
}

void RfkWindow::keyPressEvent(QKeyEvent * event) {
  Q_UNUSED(event);

  /* something */
}

void RfkWindow::startBlinking() {
  m_blinkTimer = this->startTimer(5000);
}

void RfkWindow::stopBlinking() {
  this->killTimer(m_blinkTimer);
  m_blinkTimer = 0;
  m_blink->hide();
}

void RfkWindow::timerEvent(QTimerEvent *event) {

  Q_UNUSED(event);

  this->killTimer(m_blinkTimer);

  if (m_blink->isHidden()) {
    // eyes are open; close them
    m_blink->show();
    m_blinkTimer = this->startTimer(100);
  } else {
    // eyes are closed; open them
    m_blink->hide();
    m_blinkTimer = this->startTimer(5000);
  }
}

