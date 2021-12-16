#include <iostream>
#include "Person.h"
#include "Account.h"
#include "Savings_Account.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
  Account my_account {};

  my_account.deposit(1000);
  my_account.withdraw(200);

  cout << my_account;

  Savings_Account my_s_account {100, 5};

  my_s_account.deposit(1000);
  my_s_account.withdraw(200);

  cout << my_s_account;

  return 0;
}
