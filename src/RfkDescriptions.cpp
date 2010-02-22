#include "RfkDescriptions.h"
#include <QStringList>
#include <QFile>
#include <QTextStream>

RfkDescriptions::RfkDescriptions()
{
  /* XXX this string should come from somewhere */
  QFile file("data/non-kitten-items.rfk");
  file.open(QFile::ReadOnly);
  QTextStream descriptions_stream(&file);

  m_descriptions = new QStringList();

  while (descriptions_stream.readLine() != "") {
    /* skip header */
  }

  while (!descriptions_stream.atEnd()) {
    m_descriptions->append(descriptions_stream.readLine());
  }

  /* XXX check API; do we need to close explicitly
   * or does destroying do that
   */
}

QString RfkDescriptions::description()
{
  int size = m_descriptions->size();

  if (size==0) {
    return "";
  }

  return m_descriptions->takeAt(qrand() % size);
}
