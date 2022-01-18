#include "CardType.h"
#include "iostream"

using namespace std;

class Card {

private:
  CardType fType; 
  unsigned fNumber;

public:
  Card(const CardType& aType, const unsigned aNumber) : fType(aType), fNumber(aNumber) {}

  CardType& getType() {
    return fType;
  }

  friend bool operator== (const Card& c1, const Card& c2) {
    return c1.fType == c2.fType && c1.fNumber == c2.fNumber;
  } 

  friend ostream& operator<<(ostream& aOstream, const Card& card) {
    aOstream << "Card(" << card.fType << ", " << card.fNumber << ")";

    return aOstream;
  }
};