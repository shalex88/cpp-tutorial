#ifndef CPP_TUTORIAL_S15_CHALLENGE_SAVINGS_ACCOUNT_H_
#define CPP_TUTORIAL_S15_CHALLENGE_SAVINGS_ACCOUNT_H_

#include <iostream>
#include "Account.h"

class Savings_Account : public Account {
 friend std::ostream &operator<<(std::ostream &os, const Savings_Account &account);
 private:
  static constexpr const char *def_name = "Unknown";
  static constexpr double def_balance = 0.0;
  static constexpr double def_interest_rate = 0.0;
 protected:
  double interest_rate;
 public:
  Savings_Account(std::string name = def_name, double balance = def_balance, double interest_rate = def_interest_rate);

  bool deposit(double amount);
};

#endif //CPP_TUTORIAL_S15_CHALLENGE_SAVINGS_ACCOUNT_H_
