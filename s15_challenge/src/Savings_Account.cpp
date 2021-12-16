#include <iostream>
#include "Savings_Account.h"

Savings_Account::Savings_Account(double balance, double interest_rate)
	: Account ("Savings Account", balance), interest_rate {interest_rate} {
}

Savings_Account::Savings_Account()
	: Savings_Account (0.0, 0.0) {
}

void Savings_Account::deposit(double amount) {
  amount += amount / 100 * interest_rate;
  Account::deposit(amount);
}

std::ostream &operator<<(std::ostream &os, const Savings_Account &account) {
  os << account.name << " Balance: " << account.balance << " Interest rate: " << account.interest_rate;
  return os;
}
