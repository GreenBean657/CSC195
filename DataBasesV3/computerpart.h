//
// Created by GreenBean on 4/19/25.
//

#ifndef COMPUTERPART_H
#define COMPUTERPART_H

#include <QtGui/QStandardItem>

enum Sockets {
  LGA,
  PGA,
  DDR5,
  DDR4,
  DDR3,
  PCIe,
  PCI,
};


class ComputerPart: public QStandardItem {
public:
  ComputerPart(const std::string &providedName, Sockets providedSocket): QStandardItem("Computer Part") {
    name = providedName;
    socket = providedSocket;
  }

  virtual void widgetLoader(QWidget *widget);
private:
  Sockets socket;
  std::string name;
};



#endif //COMPUTERPART_H
