#ifndef RFK_FINALE
#define RFK_FINALE 1

#include <QWidget>
#include <QTimerEvent>

/**
 * A widget which draws the final scene.
 */
class RfkFinale: public QWidget {
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

  /**
   * Called when the widget needs repainting.
   */
  virtual void paintEvent(QPaintEvent *event);

 signals:
  /**
   * Sent when the animation finishes.
   */
  void finished();

 private:
  /**
   * Distance of robot from the left-hand side of
   * the screen.
   */
  int m_robotX;

  /**
   * Size of the heart.
   */
  int m_loveSize;

  /**
   * A sprite representing robot.
   */
  QPixmap m_robot;

  /**
   * A sprite representing kitten.
   */
  QPixmap m_kitten;

  /**
   * A sprite representing the love that robot and kitten share.
   */
  QPixmap m_love;
};

#endif
