#include <iostream>
#include "Account.h"
#include "IllegalBalanceException.h"
#include "InsufficientFundsException.h"

Account::Account(std::string name, double balance)
  : name {name}, balance {balance}  {
  if (balance < 0)
	throw IllegalBalanceException {};
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
	throw InsufficientFundsException {};
  }
}

void Account::print(std::ostream &os) const {
  std::cout.precision(2);
  std::cout << std::fixed;
  os << "[Account: " << name << ": " << balance << "]";
}
