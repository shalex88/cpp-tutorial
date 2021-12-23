#include <iostream>
#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double interest_rate)
	: Savings_Account {name, balance, interest_rate}, num_withdraw {0} {
}

bool Trust_Account::deposit(double amount) {
  if (amount >= def_interest_rate) {
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

std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
  os << "[Trust Account: " << account.name << ": " << account.balance << " Interest rate: " << account.interest_rate \
  	<< "%" << " Withdrawals: " << account.num_withdraw << "]";
  return os;
}
