#ifndef CPP_TUTORIAL_S15_CHALLENGE_SAVINGS_ACCOUNT_H_
#define CPP_TUTORIAL_S15_CHALLENGE_SAVINGS_ACCOUNT_H_

#include <iostream>
#include "Account.h"

class Savings_Account : public Account {
 friend std::ostream &operator<<(std::ostream &os, const Savings_Account &account);
 protected:
  double interest_rate;
 public:
  Savings_Account(double balance, double interest_rate);
  Savings_Account();

  void deposit(double amount);
};

#endif //CPP_TUTORIAL_S15_CHALLENGE_SAVINGS_ACCOUNT_H_
