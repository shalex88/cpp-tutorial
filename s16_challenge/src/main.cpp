#include <iostream>
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"
#include "I_Printable.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
  Checking_Account frank {"Frank", 5000, 2.5};
  cout << frank << endl;
  frank.deposit(10000);
  frank.withdraw(1000);
  cout << frank << endl;

  Account *trust = new Trust_Account {"James"};
  cout << *trust << endl;
  trust->deposit(5000);
  trust->withdraw(1000);
  cout << *trust << endl;

  Account *p1 = new Checking_Account {"Larry", 10000};
  Account *p2 = new Trust_Account {"Moe", 1000};
  Account *p3 = new Savings_Account {"Curly"};
  std::vector<Account*> accounts {p1, p2, p3};

  display(accounts);
  deposit(accounts, 1000);
  withdraw(accounts, 2000);

  delete p1;
  delete p2;
  delete p3;

  return 0;
}
