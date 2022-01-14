#include <iostream>
#include "Checking_Account.h"

Checking_Account::Checking_Account(std::string name, double balance, double fee)
	: Account {name, balance}, fee {fee} {
}

bool Checking_Account::withdraw(double amount) {
  amount += fee;
  return Account::withdraw(amount);
}

void Checking_Account::print(std::ostream &os) const {
  os.precision(2);
  os << std::fixed;
  os << "[Checking Account: " << name << ": " << balance  << "]";
}

bool Checking_Account::deposit(double amount) {
  return Account::deposit(amount);
}
