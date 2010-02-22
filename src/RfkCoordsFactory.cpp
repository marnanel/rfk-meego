#include "RfkCoordsFactory.h"

RfkCoordsFactory::RfkCoordsFactory(int arena_width, int arena_height)
{
  m_width = arena_width;
  m_height = arena_height;
}

RfkCoords RfkCoordsFactory::random_position()
{
  RfkCoords candidate;

  /*
   * FIXME if count >= w*h, complain
   */
  
  do {
    candidate.first = qrand() % m_width;
    candidate.second = qrand() % m_height;
  } while (m_existing.contains(candidate));

  m_existing.append(candidate);
  return candidate;
}
