#include <QApplication>
#include <QString>
#include <QFileDialog>
#include <QDebug>

#include "src/RfkDescriptions.h"
#include "src/RfkCoords.h"
#include "src/RfkBoardModel.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  RfkBoardModel board;

  qDebug() << "Hello world!";

  board.dump();

  for (int y=-2; y<20; y++) {
    QString line;

    for (int x=-2; x<35; x++) {
      RfkItemModel *something = board.at(RfkCoords(x, y));

      line += something->asChar();
    }

    qDebug() << line;
  }

  return 0;
}
