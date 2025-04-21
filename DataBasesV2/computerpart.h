//
// Created by GreenBean on 4/19/25.
//

#ifndef COMPUTERPART_H
#define COMPUTERPART_H

#include <QtGui/QStandardItem>

/**
 * @class ComputerPart
 * @brief Base class for computer parts.
 */
class ComputerPart: public QStandardItem {
public:
  explicit ComputerPart(): QStandardItem("Computer Part") {}

  /**
   * @brief Load the widget for this computer part.
   * @param widget Master widget of this class.
   */
  virtual void widgetLoader(QWidget *widget);
private:
  std::string name;
};



#endif //COMPUTERPART_H
