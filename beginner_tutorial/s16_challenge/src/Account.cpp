#include <iostream>
#include "Account.h"

Account::Account(std::string name, double balance)
  : name {name}, balance {balance}  {
}

bool Account::deposit(double amount) {
  if (amount < 0) {
	return false;
  } else {
	balance += amount;
	return true;
  }
}

bool Account::withdraw(double amount) {
  if (balance > amount) {
	balance -= amount;
	return true;
  } else {
	return false;
  }
}

void Account::print(std::ostream &os) const {
  std::cout.precision(2);
  std::cout << std::fixed;
  os << "[Account: " << name << ": " << balance << "]";
}
