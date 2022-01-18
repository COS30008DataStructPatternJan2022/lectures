// preprocessor directive: prevents this (header) file from being included multiple times
#pragma once

#include <iostream>
#include <string>

// defines only the structure, no implementation
class SalesItem {
  // fields (attributes)
  private:
    std::string fISBN;
    unsigned fUnitsSold;
    double fRevenue;

  // operations (methods, functions)
  public:
    // constructors
    SalesItem() : fUnitsSold(0), fRevenue(0.0) {}
    SalesItem(const std::string& aBook) : fISBN(aBook), fUnitsSold(0), fRevenue(0.0) {}
    SalesItem(const std::string& aBook, unsigned aUnitsSold, double aRevenue) : fISBN(aBook), fUnitsSold(aUnitsSold), fRevenue(aRevenue) {}
    SalesItem(std::istream& aIStream) { aIStream >> *this; }
    
    // adds this item to another item (aRHS)
    SalesItem& operator+= ( const SalesItem& aRHS);
    // equality-check 2 items (aLeft, aRight)
    friend bool operator== ( const SalesItem& aLeft, const SalesItem& aRight);
    // creates an item from input stream
    friend std::istream& operator>>( std::istream& aIStream, SalesItem& aItem);
    // output an item to the output stream
    friend std::ostream& operator<<( std::ostream& aOStream, const SalesItem& aItem);

    // read the average price of item
    double getAveragePrice() const;
    // check if this.fISBN is same as another item (aRHS)
    bool hasSameISBN( const SalesItem& aRHS) const;
};