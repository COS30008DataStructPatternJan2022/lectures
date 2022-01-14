#include "iostream"
#include "SalesItem.h"

using namespace std;

int main() {
  // create a new item
  // SalesItem item("123123123", 12, 72.0);
  SalesItem item = SalesItem("123123123", 12, 72.0);

  // Operator '<<':
  cout << "Created: " << item;

  // process the item and display result
  cout << "Average price: " << item.getAveragePrice() << endl;

  // Alternative: using AbstSalesItem*
  // AbstSalesItem* item = new AbstSalesItem("123123123", 12, 72.0);
  // cout << "Average price: " << item->getAveragePrice() << endl;
  
  // create another item 
  SalesItem item2("312212313", 15, 60.0);
  // Operator '+=': add item2 into item (updating item)
  item += item2;

  // Operator '<<': display both item and item2 contents to standard output 
  cout << "++ " << item2 << " = " << item;

  // Alternative: if using AbstSalesItem*
  // item = item + item2;

  // display new price
  cout << "NEW Average price: " << item.getAveragePrice() << endl;
  
  cout << "Enter a new item (use spaces to separate field vals):" << endl;
  SalesItem item3, item4;
  // Operator '>>': create item from input stream
  cin >> item3 >> item4;

  // Alt: SalesItem item3(cin);
  cout << "Created from input stream: " << item3;

  // Operator '==': equality check
  cout << "Same as first item? " << (item == item3) << endl;

  // Operator '+': add two items 
  cout << " +  " << item << " = " << (item + item3) << endl;

  return 0;
}