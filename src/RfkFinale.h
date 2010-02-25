#ifndef RFK_FINALE
#define RFK_FINALE 1

#include <QGraphicsScene>
#include <QGraphicsView>

class RfkFinale: public QGraphicsView {
  Q_OBJECT

 public:
  RfkFinale(QWidget *parent);

 protected:
  virtual void focusInEvent(QFocusEvent *event);

 signals:
  void finished();

 private:
  QGraphicsScene m_scene;
  QGraphicsPixmapItem *m_robot;
  QGraphicsPixmapItem *m_kitten;
  QGraphicsPixmapItem *m_love;
};

#endif
