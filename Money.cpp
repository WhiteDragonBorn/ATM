#include "Money.h"

void MONEY::Money::calc_value() {
  for (int i = 0; i < curr_size; ++i) {
    value += money_[i].curr * money_[i].amount;
  }
}

void MONEY::Money::setCurr(const double& denom, const int& amount) {
  for (int i = 0; i < curr_size; ++i) {
    if (denom == money_[i].curr) {
      money_[i].amount = amount;
      break;
    }
  }
}
void MONEY::Money::setCurr(const std::vector<int>& vec) {
  if (vec.size() != curr_size) {
    throw("Bad size");
  }

  for (int i = 0; i < curr_size; ++i) {
    money_[i].amount = vec[i];
    money_[i].curr = currency[i];
  }

  calc_value();
}

MONEY::Money::Money() {
  value = 0.0;
  for (int i = 0; i < curr_size; ++i) {
    money_[i].curr = currency[i];
    money_[i].amount = 0;
  }
}

MONEY::Money::Money(const Money& other) {
  value = other.value;

  for (int i = 0; i < curr_size; ++i) {
    money_[i].amount = other.money_[i].amount;
    money_[i].curr = other.money_[i].curr;
  }
}

MONEY::Money::Money(const std::vector<int>& vec) {
  value = 0.0;
  if (vec.size() != curr_size) {
    throw("Bad size");
  }

  for (int i = 0; i < curr_size; ++i) {
    money_[i].amount = vec[i];
    money_[i].curr = currency[i];
  }

  calc_value();
}

int MONEY::Money::getCurr(const double& denom) const {
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

double MONEY::Money::getValue() const { return value; }

std::vector<int> MONEY::Money::getDenoms() const {
  std::vector<int> toReturn(curr_size, 0);
  for (int i = 0; i < curr_size; ++i) {
    toReturn[i] = money_[i].amount;
  }
  return toReturn;
}

MONEY::Money& MONEY::Money::operator=(const Money& other) {
  value = other.value;

  for (int i = 0; i < curr_size; ++i) {
    money_[i].amount = other.money_[i].amount;
  }
  return *this;
}

MONEY::Money MONEY::Money::operator+(const Money& other) {
  Money toReturn;
  toReturn.value = value + other.value;

  for (int i = 0; i < curr_size; ++i) {
    toReturn.money_[i].amount = money_[i].amount + other.money_[i].amount;
  }

  return toReturn;
}

MONEY::Money MONEY::Money::operator-(const Money& other) {
  Money toReturn;

  for (int i = curr_size - 1; i >= 0; --i) {
    int temp = money_[i].amount - other.money_[i].amount;
    // std::cout << temp << "---";
    if (temp < 0) {
      throw("Not enough currency.");
    } else {
      toReturn.money_[i].amount = temp;
    }
  }
  toReturn.calc_value();
  return toReturn;
}

double MONEY::Money::operator/(const Money& other) {
  return double(value / other.value);
}
double MONEY::Money::operator/(const double& number) {
  return double(value / number);
}

MONEY::Money MONEY::Money::operator*(const int& number) {
  Money toReturn;
  if (number < 0) {
    throw("exception.");
  }

  for (int i = 0; i < curr_size; ++i) {
    toReturn.money_[i].amount = money_[i].amount * number;
  }
  toReturn.calc_value();

  return toReturn;
}

MONEY::Money MONEY::operator*(const int& number, const MONEY::Money& obj) {
  Money toReturn;
  if (number < 0) {
    throw("exception.");
  }

  for (int i = 0; i < curr_size; ++i) {
    toReturn.money_[i].amount = obj.money_[i].amount * number;
  }
  toReturn.calc_value();

  return toReturn;
}

std::ostream& MONEY::operator<<(std::ostream& os, const MONEY::Money& obj) {
  os << obj.value;
  return os;
}

bool MONEY::Money::operator>(const Money& other) {
  return (value > other.value);
}

bool MONEY::Money::operator<(const Money& other) {
  return (other.value > value);
}

bool MONEY::Money::operator>=(const Money& other) {
  return !(value < other.value);
}

bool MONEY::Money::operator<=(const Money& other) {
  return !(value > other.value);
}
