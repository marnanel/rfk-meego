#include <QDebug>
#include "RfkItemModel.h"

RfkItemModel::RfkItemModel(RfkItemType type,
			   QString message):
  m_message(message),
  m_type(type)
{
}

void RfkItemModel::dump () {
  /* currently a stub; may remove this */
}

QString RfkItemModel::asChar() {
  /* remove this */
  return "x";
}

RfkItemType RfkItemModel::type() {
  return m_type;
}

QString RfkItemModel::message() {
  return m_message;
}
