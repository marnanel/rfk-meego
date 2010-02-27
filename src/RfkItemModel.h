#ifndef RFK_ITEM_MODEL_H
#define RFK_ITEM_MODEL_H 1

#include <QObject>
#include "RfkCoords.h"
#include "RfkItemType.h"

/**
 * A model of one item on the board.
 */
class RfkItemModel: public QObject {

  Q_OBJECT

 public:

  /**
   * Constructs an item model of the given type, with
   * the given string as a message.
   *
   * \param type     The type of the new item model.
   * \param message  The message to display.
   */
  RfkItemModel(RfkItemType type=RFK_ITEM_TYPE_SPACE,
	       QString message="");

  /**
   * Dumps this model.
   * \bug Remove this.
   */
  void dump();

  /**
   * Returns a single-character representation of this item.
   *
   * \result The representation.
   * \bug Not used; remove this.
   */
  QString asChar();

  /**
   * Returns the message associated with this item.  If this
   * item has no message, returns the empty string.
   *
   * \result  The message.
   */
  QString message();

  /**
   * Returns the type of this item.
   *
   * \result The type.
   */
  RfkItemType type();

 private:
  /**
   * The message displayed when this item is touched, if it
   * is not a wall or a space (or robot).
   */
  QString m_message;

  /**
   * The type of this item.
   */
  RfkItemType m_type;
};

#endif
