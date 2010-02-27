#ifndef RFK_APPLICATION_H
#define RFK_APPLICATION_H 1

#include <QApplication>
#include "RfkBoardModel.h"
#include "RfkController.h"
#include "RfkWindow.h"

class RfkApplication: public QApplication {

  Q_OBJECT

 public:
  RfkApplication(int &argc, char **argv);

  public slots:
  void recreateModel();

 private:
  RfkBoardModel *m_model;
  RfkController *m_controller;
  RfkWindow *m_window;
};

#endif
