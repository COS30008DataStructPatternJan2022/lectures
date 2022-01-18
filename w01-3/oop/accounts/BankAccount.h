#include "Account.cpp"

class BankAccount : public Account{
private:
  double fInterestRate;

public: 
  BankAccount (unsigned long long aNumber, double aBalance, double aInterestRate = 0.0) : Account (aNumber, aBalance) {
    fInterestRate = aInterestRate;
  }

  ~BankAccount() override {}

  bool withdraw(double aAmount) override {
    if ( this->getBalance() > aAmount) {
      return Account::withdraw(aAmount);
    } else {
      return false;
    }
  }
  
  void setInterestRate(double aInterestRate);
  double getInterestRate() const;
  bool creditIntest();
  bool applyServiceFee(double aFee);
  
};
