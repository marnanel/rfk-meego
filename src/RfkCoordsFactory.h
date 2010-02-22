#ifndef RFK_COORDS_FACTORY_H
#define RFK_COORDS_FACTORY_H 1

#include "RfkCoords.h"

class RfkCoordsFactory: public QObject {

 public:
  RfkCoordsFactory(int arena_width, int arena_height);

  RfkCoords random_position();

 private:
  int m_width;
  int m_height;
  QList<RfkCoords> m_existing;

};

#endif
