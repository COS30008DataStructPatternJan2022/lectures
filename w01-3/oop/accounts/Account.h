/* Represents a bank account */
class Account {
private:
  unsigned long long fNumber;
  double fBalance;
public:
  /* constructor */
  Account( unsigned long long aNumber, double aBalance=0.0);
  /* destructor */
  virtual ~Account() = default;

  /* deposit aAmount into this, i.e. fBalance = fBalance + aAmount */
  bool deposit( double aAmount);

  /* withdraw aAmount from this, i.e. fBalance = fBalance - aAmount */
  virtual bool withdraw( double aAmount);

  /* return the balance */
  double getBalance() const;
};