#pragma once

#include "Items.h"

class Inventory
{

private:
  int capacity;
  int numOfItems;
  Item **itemArr;

  void expand();
  void initialize(const int from);

public:
  Inventory();
  ~Inventory();

  void addItem(const Item &item);
  void removeItem(int index);
  inline void debugPrint() const 
  {
    for (size_t i=0; i< this->numOfItems; i++)
    {
      std::cout << this->itemArr[i]->debugPrint() << std::endl; 
    }
  }

};