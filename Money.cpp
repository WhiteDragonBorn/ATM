#include "Money.h"

inline double MONEY::Money::kop_to_rub() const { return kopecks * 0.01; }

void MONEY::Money::calc_value() {
  value = this->kop_to_rub();
  for (int i = 0; i < curr_size; ++i) {
    value += money_[i].curr * money_[i].amount;
  }
}

void MONEY::Money::value_to_curr() {
  money_[0].amount = std::trunc(value);
  for (int i = 1; i < curr_size; ++i) {
    if(money_[i - 1].amount / money_[i].curr < 1) break;
    money_[i].amount = money_[i - 1].amount / money_[i].curr;
    money_[i - 1].amount = money_[i - 1].amount % money_[i].curr;
  }
}

// void MONEY::Money::setCurr(const int&) {}
// void MONEY::Money::setCurr(const std::vector<int>&) {}
// void MONEY::Money::setKope(const int&) {}

MONEY::Money::Money() : kopecks(0), value(0.0) {
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

  this->calc_value();
}

int MONEY::Money::getCurr(const int& denom) const {
  int toReturn = 0;
  bool flag = false;
  for (int i = 0; i < curr_size; ++i) {
    if (money_[i].curr == denom) {
      flag = true;
      toReturn = money_[i].amount;
      break;
    }
  }
  if (!flag) throw("exception.");
  return toReturn;
}

int MONEY::Money::getKope() const { return kopecks; }

inline double MONEY::Money::getValue() const { return value; }

std::vector<int> MONEY::Money::getDenoms() const {
  std::vector<int> toReturn(9, 0);
  for (int i = 0; i < curr_size; ++i) {
    toReturn[i] = money_[i].amount;
  }
  return toReturn;
}

MONEY::Money& MONEY::Money::operator=(const Money& other) {
  this->kopecks = other.kopecks;
  for (int i = 0; i < curr_size; ++i) {
    this->money_[i].curr = currency[i];
    this->money_[i].amount = other.money_[i].amount;
  }
  return *this;
}

MONEY::Money MONEY::Money::operator+(const Money& other) {
  Money toReturn;
  toReturn.kopecks = this->kopecks + other.kopecks;
  toReturn.value = this->value + other.value;
  toReturn.value_to_curr();
  return toReturn;
}

MONEY::Money MONEY::Money::operator-(const Money& other) {
  if (this->value < other.value) {
    throw("Not enough money.");
  }
  Money toReturn;
  toReturn.value = this->value - other.value;
  toReturn.kopecks = (this->value - other.value - std::trunc(this->value - other.value) )*100;
  toReturn.value_to_curr();
  return toReturn;
}

std::ostream& MONEY::operator<<(std::ostream& os, const MONEY::Money& obj) {
  os << obj.value;
  return os;
}
