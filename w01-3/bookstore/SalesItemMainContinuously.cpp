#include "iostream"
#include "SalesItem.h"

using namespace std;

int main() {
  SalesItem lTotal, lCurrent;
  // TODO: add suitable input prompts to this program so that it is easier for 
  // user to know what to input from the command line

  // continuously create new SalesItem and group ones that have the same ISBN
  cout << "Enter SalesItem continuously:" << endl;
  if (cin >> lTotal) {
    while (cin >> lCurrent) {
      if (lTotal.hasSameISBN(lCurrent)) {
        lTotal += lCurrent;
      } else {
        cout << lTotal << endl;
        lTotal = lCurrent;
      }
      cout << lTotal << endl;
    }
  } else {
    cerr << "Error, wrong data!" << endl;
    return -1;
  }

  return 0;
}