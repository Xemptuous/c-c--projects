#include "Inventory.h"

Inventory::Inventory()
{
  capacity = 10;
  numOfItems = 0;
  itemArr = new Item*[capacity];
}

Inventory::~Inventory()
{
  for(size_t i=0; i<numOfItems; i++)
  {
    delete this->itemArr[i];
  }
  delete[] itemArr;
}


void Inventory::expand()
{
  this->capacity *= 2;

  Item **tempArr = new Item*[capacity];

  for (size_t i=0; i<numOfItems; i++)
  {
    tempArr[i] = new Item(*itemArr[i]);
  }

  for (size_t i=0; i<numOfItems; i++)
  {
    delete this->itemArr[i];
  }
  delete[] this->itemArr;

  this->itemArr = tempArr;

  this->initialize(this->numOfItems);
}


void Inventory::initialize(const int from)
{
  for (size_t i=0; i< capacity; i++)
  {
    itemArr[i] = nullptr;
  }
}


void Inventory::addItem(const Item &item)
{
  if (this->numOfItems >= this->capacity)
  {
    expand();
  }

  this->itemArr[this->numOfItems++] = new Item(item);
}


void Inventory::removeItem(int index)
{

}

