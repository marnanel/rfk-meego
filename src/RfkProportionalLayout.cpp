#include "RfkProportionalLayout.h"

/****************************************************************/

class Proportion: public QObject {

public:
  Proportion(QLayoutItem *item,
	     float x, float y,
	     float width, float height);

  ~Proportion();

  QLayoutItem *m_item;
  float m_x, m_y, m_width, m_height;
};

/****************************************************************/

Proportion::Proportion(QLayoutItem *item,
		       float x, float y,
		       float width, float height)
{
  m_item = item;
  m_x = x;
  m_y = y;
  m_width = width;
  m_height = height;
}

Proportion::~Proportion()
{
  // nothing.  We don't want to delete the item because
  // that would mess up takeAt().
}

/****************************************************************/

ProportionalLayout::ProportionalLayout(QWidget *parent, int margin, int spacing)
  : QLayout(parent)
{
  setMargin(margin);
  setSpacing(spacing);
}

ProportionalLayout::ProportionalLayout(int spacing)
{
  setSpacing(spacing);
}

ProportionalLayout::~ProportionalLayout()
{
  QLayoutItem *item;
  while ((item = takeAt(0))) {
    delete item;
  }
}

void ProportionalLayout::add(QWidget *widget)
{
  addItem(new QWidgetItem(widget));
}

void ProportionalLayout::addItem(QLayoutItem *item)
{
  itemList.append(new Proportion(item,
				 0.0, 0.0,
				 1.0, 1.0));
}

void ProportionalLayout::addItem(QLayoutItem *item,
				 float x, float y,
				 float width, float height)
{
  itemList.append(new Proportion(item,
				 x, y, width, height));
}

int ProportionalLayout::count() const
{
  return itemList.size();
}

QLayoutItem *ProportionalLayout::itemAt(int index) const
{
  if (index >= itemList.size())
    return 0;
  else
    return itemList.value(index)->m_item;
}

QLayoutItem *ProportionalLayout::takeAt(int index)
{
  Proportion *prop = takePropAt(index);
  QLayoutItem *item;
 
  if (!prop)
    {
      return 0;
    }

  item = prop->m_item;

  delete prop;
  return item;
}

Proportion *ProportionalLayout::takePropAt(int index)
{
  if (index >= 0 && index < itemList.size()) {
    Proportion *prop = itemList.takeAt(index);

    return prop;

  } else
    return 0;
}

Qt::Orientations ProportionalLayout::expandingDirections() const
{
  return 0;
}

bool ProportionalLayout::hasHeightForWidth() const
{
  return false;
}

void ProportionalLayout::setGeometry(const QRect &rect)
{
  QLayout::setGeometry(rect);
  doLayout(rect);
}

QSize ProportionalLayout::sizeHint() const
{
  return minimumSize();
}

QSize ProportionalLayout::minimumSize() const
{
  return QSize(100, 100);
}

void ProportionalLayout::doLayout(const QRect &rect) const
{
  int x = rect.x();
  int y = rect.y();

  float width = rect.width();
  float height = rect.height();

  Proportion *prop;

  foreach (prop, itemList) {
    QRect rect(
	       QPoint(x+prop->m_x*width,
		      y+prop->m_y*height),
	       QSize(prop->m_width*width,
		     prop->m_height*height)
	       );

    prop->m_item->setGeometry(rect);
  }
}
