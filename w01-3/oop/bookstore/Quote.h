#pragma once

#include <string>

/* Represents a Book item */
class Quote {
private:
  std::string fIsbn;
  double fPrice;

protected:
  void setPrice(double aPrice) {
    fPrice = aPrice;
  }

public: 
  Quote() = default;
  Quote(std::string isbn, double price) : fIsbn(isbn), fPrice(price) {}

  /* returns this.isbn */
  std::string isbn() const;

  double getPrice() const {
    return fPrice;
  }
  
  /* return the price for n copies of a book */
  virtual double netPrice(std::size_t n) const;

  /* default deconstructor */
  virtual ~Quote() = default;
};

/* IMPLEMENTATION */
std::string Quote::isbn() const {
  return fIsbn;
}

double Quote::netPrice(std:: size_t n) const {
  return fPrice * n;
}