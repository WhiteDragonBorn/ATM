#pragma once
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

namespace MONEY {

const int curr_size = 9;

const int currency[curr_size] = {1, 2, 5, 10, 50, 100, 500, 1000, 5000};

struct mUnit {
  int curr;
  int amount;
};

class Money {
 private:
  mUnit money_[curr_size];
  int kopecks;
  double value;

  double kop_to_rub() const;
  void calc_value();
  void value_to_curr();

  // set
  void setCurr(const int&);
  void setCurr(const std::vector<int>&);
  void setKope(const int&);

 public:
  Money();
  Money(const std::vector<int>&, const int&);

  // get
  int getCurr(const int&) const;
  int getKope() const;
  double getValue() const;
  std::vector<int> getDenoms() const;

  Money& operator=(const Money&);
  Money operator+(const Money&);
  Money operator-(const Money&);
  Money operator/(const Money&);
  Money operator/(const double&);
  Money operator*(const double&);
  friend Money operator/(const double&, const Money&);
  friend Money operator*(const double&, const Money&);

  friend std::ostream& operator<<(std::ostream&, const Money&);
};
}  // namespace MONEY
