#include "RfkController.h"
#include "RfkCoords.h"
#include "RfkItemModel.h"
#include <QDebug>

RfkController::RfkController() {

  qDebug() << "Board created:";

  for (int y=-2; y<20; y++) {
    QString line;

    for (int x=-2; x<35; x++) {
      RfkCoords position(x, y);

      if (m_board.robot_position() == position) {
	line += "#";
      } else {
	RfkItemModel *something = m_board.at(position);
	line += something->asChar();
      }
    }

    qDebug() << line;
  }

}
