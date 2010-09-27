#ifndef RFKFRONTLAYOUT_H
#define RFKFRONTLAYOUT_H 1

#include <QLayout>
#include <QRect>
#include <QWidgetItem>

class Proportion;

class ProportionalLayout : public QLayout
{
 public:
  ProportionalLayout(QWidget *parent, int margin = 0, int spacing = -1);
  ProportionalLayout(int spacing = -1);
  ~ProportionalLayout();

  void add(QWidget *widget);
  void addItem(QLayoutItem *item);
  void addItem(QLayoutItem *item, float x, float y, float w, float h);
  Qt::Orientations expandingDirections() const;
  bool hasHeightForWidth() const;
  int count() const;
  QLayoutItem *itemAt(int index) const;
  QSize minimumSize() const;
  void setGeometry(const QRect &rect);
  QSize sizeHint() const;
  QLayoutItem *takeAt(int index);
  Proportion *takePropAt(int index);

 private:
  void doLayout(const QRect &rect) const;

  QList<Proportion *> itemList;
};

#endif

