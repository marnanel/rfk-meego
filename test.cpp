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

  return 0;
}
