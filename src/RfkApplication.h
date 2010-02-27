#ifndef RFK_APPLICATION_H
#define RFK_APPLICATION_H 1

#include <QApplication>
#include "RfkBoardModel.h"
#include "RfkController.h"
#include "RfkWindow.h"

/**
 * The game itself.
 */
class RfkApplication: public QApplication {

  Q_OBJECT

 public:
  /**
   * Constructor.
   *
   * \param argc  The number of arguments on the commandline.
   * \param argv  The arguments on the commandline.
   */
  RfkApplication(int &argc, char **argv);

  public slots:
  /**
   * Throws away the existing model and creates a new one.
   */
  void recreateModel();

 private:
  /**
   * The model of the current board.
   */
  RfkBoardModel *m_model;

  /**
   * The controller of the game as a whole.
   */
  RfkController *m_controller;

  /**
   * The main window, which includes the view.
   */
  RfkWindow *m_window;
};

#endif
