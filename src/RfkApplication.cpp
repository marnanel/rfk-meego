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
    delete m_model;
  }

  if (m_controller) {
    delete m_controller;
  }

  m_model = new RfkBoardModel();
  m_controller = new RfkController(m_model);

  QObject::connect(m_window->view(),
		   SIGNAL(movementRequest(RfkDirection)),
		   m_controller,
		   SLOT(move(RfkDirection)) );

  QObject::connect(m_controller,
		   SIGNAL(robotMoved(RfkCoords)),
		   m_model,
		   SLOT(robotMoved(RfkCoords)) );

  QObject::connect(m_controller,
		   SIGNAL(robotMoved(RfkCoords)),
		   m_window->view(),
		   SLOT(robotMoved(RfkCoords)) );

  QObject::connect(m_controller,
		   SIGNAL(somethingDiscovered(QString)),
		   m_window->view(),
		   SLOT(showMessage(QString)) );

  QObject::connect(m_controller,
		   SIGNAL(discoveredKitten()),
		   m_window,
		   SLOT(gameWon()) );

  QObject::connect(m_controller,
		   SIGNAL(discoveredKitten()),
		   this,
		   SLOT(recreateModel()) );

  m_window->view()->populate(m_model);
}
