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
   * Constructs an item model with the given string as a message.
   * The model will not have any of its flags set.
   *
   * \param what  The message to display.
   */
  RfkItemModel(QString what);

  /**
   * Constructs an item model with no message.
   * The model will not have any of its flags set.
   */
  RfkItemModel();

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
   * Returns whether this item is a wall.
   * \return Whether this item is a wall.
   * \bug This and all the other is_*() functions should be
   *      replaced by a simple enum.
   */
  bool is_wall();
  /**
   * Returns whether this item is a space.
   * \return Whether this item is a space.
   * \bug This and all the other is_*() functions should be
   *      replaced by a simple enum.
   */
  bool is_space();
  /**
   * Returns whether this item is kitten.
   * \return Whether this item is kitten.
   * \bug This and all the other is_*() functions should be
   *      replaced by a simple enum.
   */
  bool is_kitten();

  /**
   * Sets whether this item is a wall.
   * \param whether  Whether this item is a wall.
   * \bug This and all the other set_is_*() functions should be
   *      replaced by a simple enum.
   */
  void set_is_wall(bool whether);
  /**
   * Sets whether this item is a space.
   * \param whether  Whether this item is a space.
   * \bug This and all the other set_is_*() functions should be
   *      replaced by a simple enum.
   */
  void set_is_space(bool whether);
  /**
   * Sets whether this item is kitten.
   * \param whether  Whether this item is kitten.
   * \bug This and all the other set_is_*() functions should be
   *      replaced by a simple enum.
   */
  void set_is_kitten(bool whether);

 private:
  /**
   * The message displayed when this item is touched, if it
   * is not a wall or a space.
   */
  QString m_message;

  /**
   * Whether this item is a wall.
   */
  bool m_is_wall;
  /**
   * Whether this item is a space.
   */
  bool m_is_space;
  /**
   * Whether this item is kitten.
   */
  bool m_is_kitten;
};

#endif
