#pragma once

#include "Money.h"

namespace ATM {

class Atm {
  MONEY::Money available;
  int ID;
  double min_sum;
  double max_sum;

 public:
  Atm();
  Atm(const MONEY::Money&, int);
  Atm(const Atm&);

  void insertMoney(const MONEY::Money&);
  void retrieveMoney(const MONEY::Money&);

  Atm& operator=(const Atm&);

  friend std::ostream& operator<<(std::ostream&, const Atm&);
};
}  // namespace ATM
