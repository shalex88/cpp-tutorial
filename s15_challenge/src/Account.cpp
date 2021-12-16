#include <iostream>
#include "Account.h"

Account::Account(std::string name, double balance)
  : balance {balance}, name {name} {
  std::cout << name << " created. Balance: " << balance << std::endl;
}

//Account::Account(double balance)
//  : Account (balance, "Account") {
//}

//Account::Account()
//  : Account (0) {
//}

void Account::deposit(double amount) {
  std::cout << name << " Deposit: " << amount << std::endl;
  balance += amount;
}

void Account::withdraw(double amount) {
  if (balance > amount) {
	std::cout << name << " Withdraw: " << amount << std::endl;
	balance -= amount;
  } else {
	std::cout << "Insufficient funds" << std::endl;
  }
}

std::ostream &operator<<(std::ostream &os, const Account &account) {
  os << account.name << " Balance: " << account.balance << std::endl;
  os << "-------------------------" << std::endl;
  return os;
}
