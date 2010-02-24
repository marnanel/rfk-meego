#include <QApplication>
#include <QString>
#include <QFileDialog>
#include <QDebug>

#include "src/RfkDescriptions.h"
#include "src/RfkCoords.h"
#include "src/RfkBoardModel.h"
#include "src/RfkController.h"
#include "src/RfkDirection.h"
#include "src/RfkWindow.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  RfkController controller;
  RfkWindow window;

  QObject::connect(window.view(),
		   SIGNAL(movementRequest(RfkDirection)),
		   &controller,
		   SLOT(move(RfkDirection)) );

  controller.populate(window.view());

  window.show();

  return app.exec();
}
