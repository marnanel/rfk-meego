#include <QDebug>
#include "RfkItemModel.h"

RfkItemModel::RfkItemModel(QString what):
  m_message(what),
  m_is_wall(false),
  m_is_space(false),
  m_is_kitten(false)
{
}

RfkItemModel::RfkItemModel():
  m_message(""),
  m_is_wall(false),
  m_is_space(false),
  m_is_kitten(false)
{
}

void RfkItemModel::dump () {
  /* currently a stub; may remove this */
}

QString RfkItemModel::asChar() {
  if (m_is_wall) {
    return "%";
  } else if (m_is_space) {
    return " ";
  } else if (m_is_kitten) {
    return "k";
  } else {
    return "j";
  }
}

bool RfkItemModel::is_wall() {
  return m_is_wall;
}

bool RfkItemModel::is_space() {
  return m_is_space;
}

bool RfkItemModel::is_kitten() {
  return m_is_kitten;
}

void RfkItemModel::set_is_wall(bool whether) {
  m_is_wall = whether;
}

void RfkItemModel::set_is_space(bool whether) {
  m_is_space = whether;
}

void RfkItemModel::set_is_kitten(bool whether) {
  m_is_kitten = whether;
}
