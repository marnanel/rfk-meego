#include "RfkApplication.h"

RfkApplication::RfkApplication(int &argc, char **argv):
  QApplication(argc, argv)
{
  m_model = NULL;
  m_controller = NULL;
  m_window = new RfkWindow();

  this->recreateModel();

  m_window->show();
}

void RfkApplication::recreateModel() {

  if (m_model) {
    m_model->deleteLater();
  }

  if (m_controller) {
    m_controller->deleteLater();
  }

  m_model = new RfkBoardModel();
  m_controller = new RfkController(m_model);

  QObject::connect(m_window->view(),
		   SIGNAL(movementRequest(RfkDirection, bool)),
		   m_controller,
		   SLOT(move(RfkDirection, bool)) );

  QObject::connect(m_controller,
		   SIGNAL(robotMoved(RfkCoords)),
		   m_model,
		   SLOT(robotMoved(RfkCoords)) );

  QObject::connect(m_controller,
		   SIGNAL(robotMoved(RfkCoords)),
		   m_window->view(),
		   SLOT(robotMoved(RfkCoords)) );

  QObject::connect(m_controller,
		   SIGNAL(somethingDiscovered(RfkItemModel*)),
		   m_window->view(),
		   SLOT(showMessage(RfkItemModel*)) );

  QObject::connect(m_controller,
		   SIGNAL(discoveredKitten()),
		   m_window,
		   SLOT(gameWon()) );

  QObject::connect(m_controller,
		   SIGNAL(discoveredKitten()),
		   this,
		   SLOT(recreateModel()) );

  QObject::connect(m_controller,
		   SIGNAL(somethingDiscovered(RfkItemModel*)),
		   m_model,
		   SLOT(itemVisited(RfkItemModel*)) );

  QObject::connect(m_window,
		   SIGNAL(startDemo()),
		   m_controller,
		   SLOT(startDemo()) );

  m_window->view()->populate(m_model);
}
