#include "RfkHelp.h"
#include <QFile>
#include <QString>
#include <QDebug>
#include <QUrl>

RfkHelp::RfkHelp() {

  QFile helpfile(":/resources/help.html");
  helpfile.open(QIODevice::ReadOnly|QIODevice::Text);
  QString help = helpfile.readAll();
  helpfile.close();

  this->setReadOnly(true);
  this->setHtml(help);
}

QVariant RfkHelp::loadResource (int, const QUrl &name) {

  QFile source(name.path());
  source.open(QIODevice::ReadOnly);
  QByteArray result = source.readAll();
  source.close();

  return result;
}
