// preprocessor directive: prevents this (header) file from being included multiple times
#pragma once

#include <iostream>
#include <string>
using namespace std;

class SalesItem {
  // fields (attributes)
  private:
    std::string fISBN;
    unsigned fUnitsSold;
    double fRevenue;

  // operations (methods, functions)
  public:
    // constructors
    // default constructor
    SalesItem() : fUnitsSold(0), fRevenue(0.0) {}
    // single-argument constructors -> implicit conversion
    SalesItem(const string& aBook) : fISBN(aBook), fUnitsSold(0), fRevenue(0.0) {}
    SalesItem(istream& aIStream) { aIStream >> *this; }
    // multi-argument constructor
    SalesItem(const string& aBook, unsigned aUnitsSold, double aRevenue) : fISBN(aBook), fUnitsSold(aUnitsSold), fRevenue(aRevenue) {}
    
    // adds this item to another item (aRHS)
    SalesItem& operator+= ( const SalesItem& aRHS)  {
      fUnitsSold += aRHS.fUnitsSold;
      fRevenue += aRHS.fRevenue;

      return *this;
    }

    // add-hoc operator +
    SalesItem operator+( const SalesItem& aOther)  {
      SalesItem result(*this);
      result += aOther;

      return result;
    }

    // equality-check 2 items (aLeft, aRight)
    friend bool operator== ( const SalesItem& aLeft, const SalesItem& aRight) {
      return aLeft.hasSameISBN(aRight);
    }

    // creates an item from input stream
    // URL: https://docs.microsoft.com/en-us/cpp/standard-library/overloading-the-input-operator-for-your-own-classes?view=msvc-160
    friend istream& operator>>( istream& aIStream, SalesItem& aItem) {
      aIStream >> aItem.fISBN >> aItem.fUnitsSold >> aItem.fRevenue;

      if (!aIStream) {
        // input error: reset aItem to default state
        aItem = SalesItem();
      }

      return aIStream;
    }

    // output an item to the output stream
    // URL: https://docs.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=msvc-160
    friend ostream& operator<<( ostream& aOStream, const SalesItem& aItem) {
      aOStream << "SalesItem(" << aItem.fISBN <<  "," 
               << aItem.fUnitsSold << "," 
               << aItem.fRevenue
               << ")" << endl;
      return aOStream;
    }

    // read the average price of item
    double getAveragePrice() const {
      if (this->fUnitsSold == 0) {
        return 0;
      } else {
        return this->fRevenue / this->fUnitsSold;
      }
    }

    // check if this.fISBN is same as another item (aRHS)
    bool hasSameISBN( const SalesItem& aRHS) const {
      return this->fISBN == aRHS.fISBN;
    }
};
