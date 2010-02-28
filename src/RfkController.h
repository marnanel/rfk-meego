#ifndef RFK_CONTROLLER
#define RFK_CONTROLLER 1

#include "RfkBoardModel.h"
#include "RfkDirection.h"
#include "RfkView.h"

/**
 * The controller for the game.  This decides whether
 * robot can move, moves robot when necessary, requests
 * messages about non-kitten items, and ends the game
 * when kitten is found.
 */
class RfkController: public QObject {
  Q_OBJECT

 public:
  /**
   * Creates a controller which governs the given board.
   *
   * \param board  The board.
   */
  RfkController(RfkBoardModel *board);

  public slots:
  /**
   * Received when robot is moving in a given direction.
   */
  void move(RfkDirection direction,
	    bool running=false);

 signals:
  /**
   * Sent when robot moves to a new place.
   *
   * \param newPlace  The new place.
   */
  void robotMoved(RfkCoords newPlace);

  /**
   * Sent when something is discovered and we should display
   * a message about it.  The thing that was discovered may
   * be kitten.
   */
  void somethingDiscovered(QString message);

  /**
   * Sent when robotfindskitten.  This signal is sent after
   * somethingDiscovered() announces the fact to the user.
   */
  void discoveredKitten();

 private:

  /**
   * Moves robot one step.
   *
   * \param direction  Which way robot is going.
   * \return  Whether robot actually moved.
   */
  bool moveOneStep(RfkDirection direction);

  /**
   * The board we govern.
   */
  RfkBoardModel *m_board;

  /**
   * Function to dump the board; will be removed.
   *
   * \bug Remove this.
   */
  void dump_board();
};

#endif
