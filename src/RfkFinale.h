#ifndef RFK_FINALE
#define RFK_FINALE 1

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimerEvent>

class RfkFinale: public QGraphicsView {
  Q_OBJECT

 public:
  RfkFinale(QWidget *parent);

 protected:
  virtual void focusInEvent(QFocusEvent *event);
  virtual void timerEvent(QTimerEvent *event);

 signals:
  void finished();

 private:
  void hideEverything();
  void arrangeForStart();
  void move_together();
  void grow_love();
  void vibrate();
  void centre_love();

  int m_phase;
  QGraphicsScene m_scene;
  QGraphicsPixmapItem *m_robot;
  QGraphicsPixmapItem *m_kitten;
  QGraphicsPixmapItem *m_love;
};

#endif
