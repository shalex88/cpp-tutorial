#include <iostream>
#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double interest_rate)
	: Savings_Account {name, balance, interest_rate}, num_withdraw {0} {
}

bool Trust_Account::deposit(double amount) {
  if (amount >= bonus_threshold) {
	amount += bonus;
  }
  amount += amount / 100 * interest_rate;
  return Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount) {
  num_withdraw++;
  if ((amount > (balance / 100 * max_withdraw_percent)) || (num_withdraw > max_withdraw))
	return false;
  return Account::withdraw(amount);
}

void Trust_Account::print(std::ostream &os) const {
  os.precision(2);
  os << std::fixed;
  os << "[Trust Account: " << name << ": " << balance  << "]";
}
