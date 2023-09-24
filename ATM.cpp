
#include <iostream>

#include "Money.h"

using std::cout;
using std::endl;


int main() {
  std::vector<int> vec{0, 0, 0, 0, 0, 0, 0, 0, 0};
  MONEY::Money Test(vec, 2438);
  MONEY::Money Tset(vec, 1000);
  std::cout << std::setprecision(15) << Test << " " << Tset << std::endl;


  MONEY::Money NE = Tset + Test;
  std::cout << NE;
  std::vector<int> vecc = (NE).getDenoms();
  cout << endl;
  for (auto& elem : vecc) {
    std::cout << elem << " ";
  }
  cout << (NE).getKope();
  //std::cout << Test.getCurr(5000) << "  " << Tset.getCurr(1);
}
