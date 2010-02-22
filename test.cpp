#include <QApplication>
#include <QString>
#include <QFileDialog>
#include <QDebug>

#include "src/RfkDescriptions.h"
#include "src/RfkCoords.h"
#include "src/RfkBoardModel.h"
#include "src/RfkController.h"
#include "src/RfkDirection.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  RfkController controller;

  for (int i=0; i<10; i++) {
    controller.move(RFK_DIRECTION_EAST);
  }

  return 0;
}
