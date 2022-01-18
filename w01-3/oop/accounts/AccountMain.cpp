#include "BankAccount.cpp"
#include "iostream"

using namespace std;

int main() {
  BankAccount lAccount(12345, 120.0, 0.5);

  cout << "Balance: " << lAccount.getBalance() << endl;

  Account& lBankAccountReference = lAccount;
  if (lBankAccountReference.withdraw(50.0)) {
    cout << "We got instance credit. Wow!" << endl;
    cout << "Balance: " << lAccount.getBalance() << endl;
  } else {
    cout << "The bank refused to give us money." << endl;
  }
}