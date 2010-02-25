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

  RfkBoardModel model;
  RfkController controller(&model);
  RfkWindow window;

  QObject::connect(window.view(),
		   SIGNAL(movementRequest(RfkDirection)),
		   &controller,
		   SLOT(move(RfkDirection)) );

  QObject::connect(&controller,
		   SIGNAL(robotMoved(RfkCoords)),
		   &model,
		   SLOT(robotMoved(RfkCoords)) );

  QObject::connect(&controller,
		   SIGNAL(robotMoved(RfkCoords)),
		   window.view(),
		   SLOT(robotMoved(RfkCoords)) );

  QObject::connect(&controller,
		   SIGNAL(somethingDiscovered(QString)),
		   window.view(),
		   SLOT(showMessage(QString)) );

  QObject::connect(&controller,
		   SIGNAL(discoveredKitten()),
		   &window,
		   SLOT(gameWon()) );

  window.view()->populate(model);
  window.show();

  return app.exec();
}
