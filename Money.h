#pragma once
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

  double kop_to_rub() const;

  void setCurr(const int&);
  void setCurr(const std::vector<int>&);
  void setKope(const int&);

 public:
  Money();
  Money(const std::vector<int>&, const int&);
  std::vector<int> getCurr(const int&) const;
  int getKope() const;

  Money& operator=(const Money&);
  friend std::ostream& operator<<(std::ostream&, const Money&);
};
}  // namespace MONEY
