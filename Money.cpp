#include "Money.h"

inline double MONEY::Money::kop_to_rub() const { return kopecks * 0.01; }

void MONEY::Money::setCurr(const int&) {}
void MONEY::Money::setCurr(const std::vector<int>&) {}
void MONEY::Money::setKope(const int&) {}

MONEY::Money::Money() : kopecks(0) {
  for (int i = 0; i < curr_size; ++i) {
    money_[i].curr = currency[i];
    money_[i].amount = 0;
  }
}

MONEY::Money::Money(const std::vector<int>& vec, const int& kope)
    : kopecks(kope) {
  if (vec.size() != curr_size) {
    throw("Bad size");
  }

  for (int i = 0; i < curr_size; ++i) {
    money_[i].amount = vec[i];
    money_[i].curr = currency[i];
  }
}

std::vector<int> MONEY::Money::getCurr(const int&) const {}
int MONEY::Money::getKope() const {}

MONEY::Money& MONEY::Money::operator=(const Money& other) {
  this->kopecks = other.kopecks;
  for (int i = 0; i < curr_size; ++i) {
    this->money_[i].curr = currency[i];
    this->money_[i].amount = other.money_[i].amount;
  }
  return *this;
}

std::ostream& MONEY::operator<<(std::ostream& os, const MONEY::Money& obj) {
  double summa(obj.kop_to_rub());

  for (int i = 0; i < MONEY::curr_size; ++i) {
    summa += obj.money_[i].curr * obj.money_[i].amount;
  }

  os << summa;
  return os;
}
