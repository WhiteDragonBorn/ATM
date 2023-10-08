#include "Atm.h"

ATM::Atm::Atm() : available() {
  ID = -1;
  min_sum = 0;
  max_sum = 0;
}

ATM::Atm::Atm(const MONEY::Money& obj, int id_) : available(obj) {
  ID = id_;
  min_sum = 0.0;
  max_sum = obj.getValue();
}

ATM::Atm::Atm(const Atm& other) : available(other.available) {
  ID = other.ID;
  min_sum = other.min_sum;
  max_sum = other.max_sum;
}

ATM::Atm& ATM::Atm::operator=(const Atm& other) {
  available = other.available;
  ID = other.ID;
  min_sum = other.min_sum;
  max_sum = other.max_sum;
  return *this;
}

void ATM::Atm::insertMoney(const MONEY::Money& other) {
  available = available + other;
  max_sum += other.getValue();
}

void ATM::Atm::retrieveMoney(const MONEY::Money& other) {
  if (other.getValue() >= min_sum && other.getValue() <= max_sum) {
    available = available - other;
    max_sum -= other.getValue();
  }
}

std::ostream& ATM::operator<<(std::ostream& os, const Atm& atm) {
  os << "ID: " << atm.ID << " Available sum: " << atm.available.getValue()
     << std::endl;
  return os;
}
