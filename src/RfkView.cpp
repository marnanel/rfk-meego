#include "RfkView.h"
#include <QGridLayout>
#include <QLabel>
#include <QDebug>
#include <QMessageBox>
#include <QPainter>

/**
 * A message box that can optionally remove itself
 * after the user has had time to read it.
 */
class TemporaryMessageBox: public QMessageBox {
public:

  /**
   * Constructs a simple dialogue box.
   *
   * \param message    The message in the dialogue box.
   * \param temporary  Whether it should close itself
   *                   when the user has had time to
   *                   read it.
   */
  TemporaryMessageBox(QString message,
		      bool temporary):
    QMessageBox(QMessageBox::Information,
		"robotfindskitten",
		message) {

    if (temporary) {
      // Let's assume that people read at around 200wpm.
      // That's about 3 words per second.
      // An average word is about five characters plus a space.
      // So people read at about 21 characters per second.
      // So let's divide the length by 0.021 to get the number
      // of milliseconds to display.
      this->startTimer(message.length() / 0.021);
    }
  };

  /**
   * Closes this dialogue box.
   *
   * \param event  Details of the timer event.
   */
  void timerEvent(QTimerEvent *event) {
    this->killTimer(event->timerId());
    this->close();
  };
};

RfkView::RfkView(): m_grid(new QGridLayout()) {

  m_grid = new QGridLayout;
  this->setLayout(m_grid);

  m_grid->setSpacing(0);

  // arrows
  m_keymap[Qt::Key_Up]       = RFK_DIRECTION_NORTH;
  m_keymap[Qt::Key_PageUp]   = RFK_DIRECTION_NORTHEAST;
  m_keymap[Qt::Key_Right]    = RFK_DIRECTION_EAST;
  m_keymap[Qt::Key_PageDown] = RFK_DIRECTION_SOUTHEAST;
  m_keymap[Qt::Key_Down]     = RFK_DIRECTION_SOUTH;
  m_keymap[Qt::Key_End]      = RFK_DIRECTION_SOUTHWEST;
  m_keymap[Qt::Key_Left]     = RFK_DIRECTION_WEST;
  m_keymap[Qt::Key_Home]     = RFK_DIRECTION_NORTHWEST;

  // vi / nethack
  m_keymap[Qt::Key_K]        = RFK_DIRECTION_NORTH;
  m_keymap[Qt::Key_U]        = RFK_DIRECTION_NORTHEAST;
  m_keymap[Qt::Key_L]        = RFK_DIRECTION_EAST;
  m_keymap[Qt::Key_N]        = RFK_DIRECTION_SOUTHEAST;
  m_keymap[Qt::Key_J]        = RFK_DIRECTION_SOUTH;
  m_keymap[Qt::Key_B]        = RFK_DIRECTION_SOUTHWEST;
  m_keymap[Qt::Key_H]        = RFK_DIRECTION_WEST;
  m_keymap[Qt::Key_Y]        = RFK_DIRECTION_NORTHWEST;

  // other
  m_keymap[Qt::Key_D]        = RFK_DIRECTION_DEMO;
  m_keymap[Qt::Key_R]        = RFK_DIRECTION_RANDOM;

  // in the GTK version, ctrl-Q was a secret keystroke
  // that showed you where kitten was; should we keep
  // that?
}

void RfkView::populate(RfkBoardModel *board) {

  RfkCoords southeast = board->southeast_corner();
  m_robot = board->robot_position();

  while (QLayoutItem *child = m_grid->takeAt(0)) {
    child->widget()->deleteLater();
  }

  for (int x=0; x<=southeast.x(); x++) {
    for (int y=0; y<=southeast.y(); y++) {
      RfkCoords position(x,y);
      QLabel *label;

      if (m_robot==position) {
	label = new QLabel("<span style=\"color:#FFF\">#</span>");
	label->setAlignment(Qt::AlignCenter);
	label->setTextFormat(Qt::RichText);
      } else {
	RfkItemModel* item = board->at(position);

	if (item->type() == RFK_ITEM_TYPE_SPACE) {
	  label = new QLabel(" ");
	} else {
	  label = this->random_character();
	}
      }

      m_grid->addWidget(label,
			y, x);
    }
  }
}

QLabel* RfkView::random_character() {

  char symbol = qrand()%('~'-'!') + '!';
  int colour = qrand() % 0xFFFFFF;
  QString text("<span style=\"color:#%2\">%1</span>");

  text = text.arg(symbol).arg(colour, 6, 16);

  QLabel *result = new QLabel();

  result->setAlignment(Qt::AlignCenter);
  result->setText(text);
  result->setTextFormat(Qt::RichText);
  
  return result;
}

void RfkView::keyPressEvent(QKeyEvent * event) {

  if (m_keymap.contains(event->key())) {
    emit movementRequest(m_keymap[event->key()],
			 event->modifiers() & Qt::ShiftModifier);
    event->accept();
  } else {
    event->ignore();
  }
}

void RfkView::mousePressEvent(QMouseEvent *event) {
  int quarter_width = this->width() / 4;
  int quarter_height = this->height() / 4;
  int quadrant= int(event->x()/quarter_width) +
    int(event->y()/quarter_height)*4;

  const RfkDirection directions[16] =
    {
      RFK_DIRECTION_NORTHWEST, RFK_DIRECTION_NORTH, RFK_DIRECTION_NORTH, RFK_DIRECTION_NORTHEAST,
      RFK_DIRECTION_WEST,      RFK_DIRECTION_NONE,  RFK_DIRECTION_NONE,  RFK_DIRECTION_EAST,
      RFK_DIRECTION_WEST,      RFK_DIRECTION_NONE,  RFK_DIRECTION_NONE,  RFK_DIRECTION_EAST,
      RFK_DIRECTION_SOUTHWEST, RFK_DIRECTION_SOUTH, RFK_DIRECTION_SOUTH, RFK_DIRECTION_SOUTHEAST
    };

  emit movementRequest(directions[quadrant], false);
  event->accept();
}

void RfkView::robotMoved(RfkCoords where) {

  QLayoutItem *robot = m_grid->itemAtPosition(m_robot.y(), m_robot.x());
  QLayoutItem *space = m_grid->itemAtPosition(where.y(), where.x());

  m_grid->removeItem(robot);
  m_grid->removeItem(space);
  m_grid->addItem(space, m_robot.y(), m_robot.x());
  m_grid->addItem(robot, where.y(), where.x());
  
  m_robot = where;
}

void RfkView::showMessage(QString message) {

  /* FIXME Pop up a banner instead under Maemo */

  TemporaryMessageBox info(message, true);
  info.exec();
}

void RfkView::showMessage(RfkItemModel *item) {
  this->showMessage(item->message());
}

void RfkView::paintEvent(QPaintEvent *)
{
  int quarter_width = this->width()/4;
  int quarter_height = this->height()/4;

  QPainter painter(this);
  QPen grey(Qt::darkGray);

  painter.fillRect(0, 0, this->width(), this->height(),
		   Qt::black);

  painter.setPen(grey);

  painter.drawRect(quarter_width, 0,
		   quarter_width*2, quarter_height);
  painter.drawRect(quarter_width, quarter_height*3,
		   quarter_width*2, quarter_height);
  painter.drawRect(0, quarter_height,
		   quarter_width, quarter_height*2);
  painter.drawRect(quarter_width*3, quarter_height,
		   quarter_width, quarter_height*2);
}
