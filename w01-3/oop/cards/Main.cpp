#include "Card.h"
#include "iostream"

using namespace std;

void checkCardByVal(const Card c1, const Card c2) {
  if (c1 == c2) {
    cout << c1 <<  " == " << c2 << endl;
  } else {
    cout << c1 << " != " << c2 << endl;
  }
}

void checkCardByRef(Card * c1, Card  * c2) {
  // todo: how do we improve this check?
  if (c1 == c2) {
    cout << c1 << " (" << c1<< ") " << " == " << c2 << " (" << c2<< ") "  << endl;
  } else {
    cout << c1 << " (" << c1<< ") " << " != " << c2 << " (" << c2<< ") " << endl;
  }
}

void valueModel() {
  cout << "valueModel()" << endl;
  Card c1(Diamond, 14);
  Card c2 = Card(Diamond, 14);
  Card c3 = Card(Spade, 14);

  checkCardByVal(c1, c2);
  checkCardByVal(c1, c3);
}

void refModel() {
  cout << "refModel()" << endl;
  Card * c1 = new Card(Diamond, 14);
  Card * c2 = new Card(Diamond, 14);
  Card * c3 = new Card(Spade, 14);

  checkCardByRef(c1, c2);
  checkCardByRef(c2, c3);

  delete c1, c2, c3;
}

int main() {
  valueModel();

  refModel();

  return 0;
}