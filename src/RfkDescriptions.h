#ifndef RFK_DESCRIPTIONS_H
#define RFK_DESCRIPTIONS_H 1

#include <QString>
#include <QStringList>

class RfkDescriptions: public QObject {

 public:
  RfkDescriptions();

  /**
   * Returns a string randomly chosen from the
   * string list.  If there are no remaining
   * strings, returns the empty string.
   */
  QString description();

 private:
  QStringList *m_descriptions;
};

#endif
