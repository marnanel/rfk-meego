#include "RfkVibrate.h"
#include <QDebug>

RfkVibrate::RfkVibrate():
  QObject()
{
}

void RfkVibrate::vibrate()
{
  qDebug() << "Vibrate here.";
}
