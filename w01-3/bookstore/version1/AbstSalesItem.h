// preprocessor directive: prevents this (header) file from being included multiple times
#pragma once

#include <iostream>
#include <string>
using namespace std;

// defines only the structure, no implementation
class AbstSalesItem {
  // fields (attributes)
  private:
    std::string fISBN;
    unsigned fUnitsSold;
    double fRevenue;

  // operations (methods, functions)
  public:
    // constructors
    AbstSalesItem() : fUnitsSold(0), fRevenue(0.0) {}
    AbstSalesItem(const string& aBook) : fISBN(aBook), fUnitsSold(0), fRevenue(0.0) {}
    AbstSalesItem(const string& aBook, unsigned aUnitsSold, double aRevenue) : fISBN(aBook), fUnitsSold(aUnitsSold), fRevenue(aRevenue) {}
    AbstSalesItem(istream& aIStream) { aIStream >> *this; }
    
    // adds this item to another item (aRHS)
    AbstSalesItem& operator+= ( const AbstSalesItem& aRHS);
    // equality-check 2 items (aLeft, aRight)
    friend bool operator== ( const AbstSalesItem& aLeft, const AbstSalesItem& aRight);
    // creates an item from input stream
    friend istream& operator>>( istream& aIStream, AbstSalesItem& aItem);
    // output an item to the output stream
    friend ostream& operator<<( ostream& aOStream, const AbstSalesItem& aItem);

    // read the average price of item
    double getAveragePrice() const;
    // check if this.fISBN is same as another item (aRHS)
    bool hasSameISBN( const AbstSalesItem& aRHS) const;
};