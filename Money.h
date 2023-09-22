#pragma once
#include <iostream>
#include <string>

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

  double kop_to_rub() const { return kopecks * 0.01; }

 public:
  Money() : kopecks(0) {
    for (int i = 0; i < curr_size; ++i) {
      money_[i].curr = currency[i];
      money_[i].amount = 0;
    }
  }

  friend std::ostream& operator<<(std::ostream&, const Money&);
};
}  // namespace MONEY
