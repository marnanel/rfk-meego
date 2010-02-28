#ifndef RFK_VIEW
#define RFK_VIEW 1

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QKeyEvent>
#include <QHash>
#include "RfkBoardModel.h"

/**
 * A view of the game board.
 */
class RfkView: public QWidget {

  Q_OBJECT

 public:
  /**
   * Creates a new view.
   */
  RfkView();

  /**
   * Populates the game board according to a model.
   *
   * \param board  The model.
   */
  void populate(RfkBoardModel *board);

  public slots:
  /**
   * Received whenever robot moves.
   *
   * \param where  Where robot moved to.
   */
  void robotMoved(RfkCoords where);

  /**
   * A request to display a message.  Under Maemo,
   * this will be in a note.  Otherwise, it will
   * be in a dialogue box.
   *
   * \bug Maemo support is not yet added.
   */
  void showMessage(QString message);

 signals:
  /**
   * Sent when the user moves robot in a particular
   * direction.
   *
   * \param direction  The direction in which to move.
   */
  void movementRequest(RfkDirection direction);

 protected:
  /**
   * Called when the user presses a key.
   */
  void keyPressEvent(QKeyEvent *event);

  /**
   * Called when the user taps on the screen.
   */
  void mousePressEvent(QMouseEvent *event);

 private:
  /**
   * A map of keys to directions.  When the user presses
   * the given key, robot moves in the given direction.
   */
  QHash<int, RfkDirection> m_keymap;

  /**
   * Where robot is.
   */
  RfkCoords m_robot;

  /**
   * Returns a label with a random character in a random
   * colour.
   */
  QLabel* random_character();

  /**
   * The layout for this widget.
   */
  QGridLayout *m_grid;
};

#endif
