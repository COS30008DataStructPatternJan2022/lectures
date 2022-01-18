#pragma once

#include "Quote.h"

/* Represents a Book item that can be sold at a discount price based on the number of copies */
class BulkQuote : public Quote {
public: 
  BulkQuote() : Quote() {};
  BulkQuote(std::string isbn, double price) : Quote(isbn, price) {}
  
  /* @override */
  double netPrice(std::size_t n) const override;
};

/* IMPLEMENTATION  */
double BulkQuote::netPrice(std::size_t n) const {
  /* todo: can we use getPrice() instead? */
  if (n > 10) {
    return Quote::netPrice(n) * 0.1;
  } else if (n < 50) {
    return Quote::netPrice(n) * 0.3;
  } else {
    return Quote::netPrice(n) * 0.5;
  }
}