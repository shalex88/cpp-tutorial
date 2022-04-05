#include <iostream>
#include "Savings_Account.h"

Savings_Account::Savings_Account(std::string name, double balance, double interest_rate)
	: Account {name, balance}, interest_rate {interest_rate} {
}

bool Savings_Account::deposit(double amount) {
  amount += amount / 100 * interest_rate;
  return Account::deposit(amount);
}

void Savings_Account::print(std::ostream &os) const {
  os.precision(2);
  os << std::fixed;
  os << "[Savings Account: " << name << ": " << balance  << "]";
}

bool Savings_Account::withdraw(double amount) {
  return Account::withdraw(amount);
}
