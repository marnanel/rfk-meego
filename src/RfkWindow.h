#ifndef RFK_WINDOW
#define RFK_WINDOW 1

#include <QStackedWidget>
#include "RfkView.h"

/**
 * The main window of the game.  Contains the view.
 */
class RfkWindow: public QStackedWidget {
 Q_OBJECT

 public:
  /**
   * Constructs the window.
   */
  RfkWindow();

  /**
   * Returns our view, so that it can be manipulated
   * by other classes.
   *
   * \result  The view
   */
  RfkView* view();

 protected:
  /**
   * Called when the user presses a key.
   *
   * \param event  Details of the keypress.
   */
  void keyPressEvent(QKeyEvent *event);

 public slots:
  /**
   * Received when the game begins.
   * \bug Use camelcase.
   */
  void play_game();

  /**
   * Received when the demo begins.
   * \bug Should probably be private.
   */
  void playDemo();

  /**
   * Received when the help is requested.
   * \bug Should probably be private.
   */
  void showHelp();

  /**
   * Received when the game is won.
   */
  void gameWon();

  /**
   * Received when the game restarts (either because it's
   * being ended early, or because it's been won and the
   * user wants to play again).
   */
  void restart();

  /**
   * Makes kitten close or open its eyes.
   */
  void timerEvent(QTimerEvent *event);

 signals:
  /**
   * Sent when the demo should begin.
   */
  void startDemo();

 private:
  /**
   * A view of the board.
   */
  RfkView *m_view;

  /**
   * Kitten's eyes, closed.
   */
  QLabel *m_blink;

  /**
   * ID of the timer that makes kitten blink.
   */
  int m_blinkTimer;

  /**
   * Starts kitten blinking.
   */
  void startBlinking();

  /**
   * Stops kitten blinking.
   */
  void stopBlinking();

  /**
   * Creates the front screen.  This exists to simplify
   * the constructor.
   *
   * \result  The front screen.
   */
  QWidget* prepare_front_screen();
};

#endif
