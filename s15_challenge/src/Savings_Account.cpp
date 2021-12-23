#include <iostream>
#include "Savings_Account.h"

Savings_Account::Savings_Account(std::string name, double balance, double interest_rate)
	: Account {name, balance}, interest_rate {interest_rate} {
}

bool Savings_Account::deposit(double amount) {
  amount += amount / 100 * interest_rate;
  return Account::deposit(amount);
}

std::ostream &operator<<(std::ostream &os, const Savings_Account &account) {
  os << "[Savings Account: " << account.name << ": " << account.balance << " Interest rate: " << account.interest_rate << "%" << "]";
  return os;
}
