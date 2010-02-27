#ifndef RFK_FINALE
#define RFK_FINALE 1

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimerEvent>

/**
 * A widget which draws the final scene.
 */
class RfkFinale: public QGraphicsView {
  Q_OBJECT

 public:
  /**
   * Constructs the widget.
   * \param parent  The parent widget.
   */
  RfkFinale(QWidget *parent);

 protected:
  /**
   * Called when we receive focus; this starts the
   * animation playing.
   */
  virtual void focusInEvent(QFocusEvent *event);

  /**
   * Called every so often by a timer; this is used
   * to run the animation.
   */
  virtual void timerEvent(QTimerEvent *event);

 signals:
  /**
   * Sent when the animation finishes.
   */
  void finished();

 private:
  /**
   * Hides every sprite.  Used so that the old positions
   * aren't shown for a split second when the animation
   * begins again.
   */
  void hideEverything();

  /**
   * Arranges the sprites ready to start the animation.
   */
  void arrangeForStart();

  /**
   * Moves robot and kitten one step closer to one another.
   */
  void move_together();

  /**
   * Grows a heart between robot and kitten.
   */
  void grow_love();

  /**
   * Under Maemo, causes the device to vibrate.  Otherwise,
   * does nothing.
   *
   * \bug This is still a stub.
   */
  void vibrate();

  /**
   * Convenience function to centre the heart sprite on the screen.
   */
  void centre_love();

  /**
   * Phase of the animation.  Used by timerEvent() to know which of
   * its helper methods to call.
   */
  int m_phase;

  /**
   * The scene where the sprites live.
   */
  QGraphicsScene m_scene;

  /**
   * A sprite representing robot.
   */
  QGraphicsPixmapItem *m_robot;

  /**
   * A sprite representing kitten.
   */
  QGraphicsPixmapItem *m_kitten;

  /**
   * A sprite representing the love that robot and kitten share.
   */
  QGraphicsPixmapItem *m_love;
};

#endif
