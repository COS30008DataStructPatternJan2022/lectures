#include "SalesItem.h"

using namespace std;

// implements an operation +
SalesItem& SalesItem::operator += (const SalesItem& aRHS) {
  fUnitsSold += aRHS.fUnitsSold;
  fRevenue += aRHS.fRevenue;

  return *this;
}

// implements operation: getAveragePrice
double SalesItem::getAveragePrice() const {
  if (this->fUnitsSold == 0) {
    return 0;
  } else {
    return this->fRevenue / this->fUnitsSold;
  }
}

int main() {
  // create a new item
  SalesItem item("123123123", 12, 72.0);
  // process the item and display result
  cout << "Average price: " << item.getAveragePrice() << endl;
  // Alternative: using SalesItem*
  // SalesItem* item = new SalesItem("123123123", 12, 72.0);
  // cout << "Average price: " << item->getAveragePrice() << endl;
  
  // create another item 
  SalesItem item2("312212313", 15, 60.0);
  item += item2;

  // Alternative: if using SalesItem*
  // item = item + item2;
  cout << "NEW Average price: " << item.getAveragePrice() << endl;

  return 0;
}