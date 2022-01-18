#include "Account.h"

/* IMPLEMENTATION */

// todo: what is another way of initialising the attributes?
Account::Account (unsigned long long aNumber, double aBalance) {
  fNumber = aNumber;
  fBalance = aBalance;
}

bool Account::deposit(double aAmount) {
  fBalance += aAmount;
  return true;
}

bool Account::withdraw(double aAmount) {
  // does not perform range check on balance
  fBalance -= aAmount;
  return true;
}

double Account::getBalance() const {
  return fBalance;
}