#ifndef RFK_VIBRATE_H
#define RFK_VIBRATE_H 1

#include <QObject>

class RfkVibrate: public QObject {
  Q_OBJECT

public:
  RfkVibrate();

  /**
   * Causes the device to vibrate,
   * if this is possible.  If it's
   * not possible, does nothing.
   */
  void vibrate();

};

#endif /* !RFK_VIBRATE_H */
