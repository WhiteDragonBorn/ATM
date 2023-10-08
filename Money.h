#pragma once
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

namespace MONEY {

const int curr_size = 13;

const double currency[curr_size] = {0.01, 0.05, 0.1, 0.5, 1,    2,   5,
                                    10,   50,   100, 500, 1000, 5000};

struct mUnit {
  double curr;
  int amount;
};

class Money {
 private:
  mUnit money_[curr_size];
  double value;

  void calc_value();

  // set
  void setCurr(const double&, const int&);
  void setCurr(const std::vector<int>&);

 public:
  Money();
  Money(const Money&);
  Money(const std::vector<int>&);

  // get
  int getCurr(const double&) const;
  double getValue() const;
  std::vector<int> getDenoms() const;

  Money& operator=(const Money&);

  Money operator+(const Money&);
  Money operator-(const Money&);

  double operator/(const Money&);
  double operator/(const double&);

  Money operator*(const int&);
  friend Money operator*(const int&, const Money&);

  friend std::ostream& operator<<(std::ostream&, const Money&);

  bool operator>(const Money&);
  bool operator<(const Money&);
  bool operator>=(const Money&);
  bool operator<=(const Money&);
};
}  // namespace MONEY
