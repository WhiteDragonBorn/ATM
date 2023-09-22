#include "Money.h"

std::ostream& MONEY::operator<<(std::ostream& os, const MONEY::Money& obj) {
  double summa(obj.kop_to_rub());

  for (int i = 0; i < MONEY::curr_size; ++i) {
    summa += obj.money_[i].curr * obj.money_[i].amount;
  }

  os << summa;
  return os;
}
