#ifndef RFK_HELP
#define RFK_HELP 1

#include <QTextEdit>

/**
 * The help window.
 */
class RfkHelp: public QTextEdit {
 Q_OBJECT

 public:
  /**
   * Constructs the help window.
   */
  RfkHelp();

  /**
   * Loads resources.
   */
  QVariant loadResource (int type, const QUrl &name);
};

#endif
