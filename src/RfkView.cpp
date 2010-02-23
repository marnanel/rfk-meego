#include "RfkView.h"
#include <QGridLayout>
#include <QLabel>
#include <QDebug>

RfkView::RfkView(): m_grid(new QGridLayout()) {
  this->setLayout(m_grid);
}

void RfkView::populate(RfkBoardModel &board) {

  RfkCoords southeast = board.southeast_corner();
  RfkCoords robot = board.robot_position();

  for (int x=0; x<=southeast.x(); x++) {
    for (int y=0; y<=southeast.y(); y++) {
      RfkCoords position(x,y);
      QLabel *label;

      QLayoutItem *old = m_grid->itemAtPosition(y, x);
      if (old) {
	m_grid->removeItem(old);
	delete old;
      }

      if (robot==position) {
	label = new QLabel("#");
      } else {
	RfkItemModel* item = board.at(position);

	if (item->is_space()) {
	  label = new QLabel();
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
  qDebug() << event->key();
}
