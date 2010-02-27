#ifndef RFK_DESCRIPTIONS_H
#define RFK_DESCRIPTIONS_H 1

#include <QString>
#include <QStringList>

/**
 * A factory to produce random descriptions
 * of non-kitten items.
 *
 * \bug Should have a way to say when it's exhausted.
 *      (Use a signal, maybe?  Or just have a boolean method)
 */
class RfkDescriptions: public QObject {

  Q_OBJECT

 public:
  /**
   * Constructor.
   *
   * \bug Should take a parameter for the source of the data.
   */
  RfkDescriptions();

  /**
   * Returns a string randomly chosen from the
   * string list.  If there are no remaining
   * strings, returns the empty string.
   */
  QString description();

 private:
  /**
   * List of descriptions we haven't used yet.
   */
  QStringList *m_descriptions;
};

#endif
