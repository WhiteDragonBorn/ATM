
#include <iostream>

#include "Atm.h"
#include "Money.h"

using std::cout;
using std::endl;

int main() {
  std::vector<int> vec{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3};

  MONEY::Money Test(vec);

  vec[6] = 10;
  MONEY::Money Test_2(vec);

  cout << std::setprecision(15) << Test << endl << Test_2 << endl;
  cout << Test + Test_2 << endl
       << endl
       << Test / Test_2 << endl
       << Test / 2 << endl
       << Test * 2 << endl
       << 2 * Test << endl;
  cout << Test_2 - Test << endl;

  ATM::Atm new_atm(Test, 443);

  cout << new_atm;
  new_atm.insertMoney(Test_2);
  cout << new_atm;
  new_atm.retrieveMoney(Test);
  cout << new_atm;
  new_atm.retrieveMoney(Test);
  cout << new_atm;
}
