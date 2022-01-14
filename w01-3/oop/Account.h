class Account {
  private:
    unsigned long long fNumber;
    double fBalance;
  public:
    Account( unsigned long long aNumber, double aBalance=0.0);
    // destructor
    virtual ~Account() {}

    bool deposit( double aAmount);
    virtual bool withdraw( double aAmount);

    double getBalance() const;
};