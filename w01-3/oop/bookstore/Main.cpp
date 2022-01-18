#include "Quote.h"
#include "BulkQuote.h"
#include <iostream>
#include <string>

using namespace std;

/* calculate and print the net price for n copies of item */
double printTotal(ostream &os, const Quote &item, size_t n) {
  double ret = item.netPrice(n);  // dynamic binding

  os << "ISBN: " << item.isbn() 
    << " # sold: " << n 
    << " total due: " << ret << endl;
    return ret;
}

int main() {
  Quote quote1("112132131", 15);
  BulkQuote quote2("856567546", 20);
  
  int n = 30;
  cout << quote1.isbn() << " has net-price(" << n << "):  " << quote1.netPrice(n) << endl;
  cout << quote2.isbn() << " has net-price(" << n << "):  " << quote2.netPrice(n) << endl;
  
  return 0;
}