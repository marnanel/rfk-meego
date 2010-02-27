#include "src/RfkApplication.h"

/**
 * \mainpage  robotfindskitten
 * robotfindskitten is a “Zen simulation”, originally
 * written by Leonard Richardson for DOS. The user plays robot,
 * who must find kitten in a field of non-kitten items.
 * This is a generic Qt port, but it is intended to be used
 * with Maemo on the Nokia N900 (and later on, MeeGo).
 */

/**
 * The main function.
 */
int main(int argc, char *argv[])
{
  RfkApplication app(argc, argv);
  return app.exec();
}
