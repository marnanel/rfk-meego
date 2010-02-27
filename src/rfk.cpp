#include "src/RfkApplication.h"

/**
 * \mainpage  robotfindskitten
 * robotfindskitten is a “Zen simulation”, originally
 * written by Leonard Richardson for DOS. The user plays robot,
 * who must find kitten in a field of non-kitten items.
 * This is a generic Qt port, but it is intended to be used
 * with Maemo on the Nokia N900 (and later on, MeeGo).
 *
 * \todo Fix the second-round problem.
 * \todo Add clicking on the board to move.
 * \todo Add "running" capability to the controller.
 * \todo Add chequers to the view showing where to click.
 * \todo Add the online help.
 * \todo Add random movement.
 * \todo Add the demo button.
 * \todo Test on Maemo.
 * \todo Add Maemo-specific functions.
 */

/**
 * The main function.
 */
int main(int argc, char *argv[])
{
  RfkApplication app(argc, argv);
  return app.exec();
}
