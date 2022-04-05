#include <iostream>
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
  cout.precision(2);
  cout << std::fixed;

  std::vector<Account> accounts;
  accounts.push_back(Account {});
  accounts.push_back(Account {"Larry"});
  accounts.push_back(Account {"Moe", 2000} );
  accounts.push_back(Account {"Curly", 5000} );

  display(accounts);
  deposit(accounts, 1000);
  withdraw(accounts,2000);

  std::vector<Savings_Account> sav_accounts;
  sav_accounts.push_back(Savings_Account {} );
  sav_accounts.push_back(Savings_Account {"Larry"} );
  sav_accounts.push_back(Savings_Account {"Moe", 2000} );
  sav_accounts.push_back(Savings_Account {"Curly", 5000, 5.0} );

  display(sav_accounts);
  deposit(sav_accounts, 1000);
  withdraw(sav_accounts, 2000);

  std::vector<Checking_Account> check_accounts;
  check_accounts.push_back(Checking_Account {} );
  check_accounts.push_back(Checking_Account {"Larry"} );
  check_accounts.push_back(Checking_Account {"Moe", 2000} );
  check_accounts.push_back(Checking_Account {"Curly", 5000, 2.0} );

  display(check_accounts);
  deposit(check_accounts, 1000);
  withdraw(check_accounts, 2000);

  std::vector<Trust_Account> trust_accounts;
  trust_accounts.push_back(Trust_Account {} );
  trust_accounts.push_back(Trust_Account {"Larry"} );
  trust_accounts.push_back(Trust_Account {"Moe", 2000} );
  trust_accounts.push_back(Trust_Account {"Curly", 5000, 5.0} );

  display(trust_accounts);
  deposit(trust_accounts, 1000);
  withdraw(trust_accounts, 500);
  withdraw(trust_accounts, 300);
  withdraw(trust_accounts, 200);
  withdraw(trust_accounts, 100);

  return 0;
}
