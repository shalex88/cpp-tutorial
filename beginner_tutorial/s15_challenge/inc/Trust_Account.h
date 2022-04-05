#ifndef CPP_TUTORIAL_S15_CHALLENGE_TRUST_ACCOUNT_H_
#define CPP_TUTORIAL_S15_CHALLENGE_TRUST_ACCOUNT_H_

#include <iostream>
#include "Savings_Account.h"

class Trust_Account : public Savings_Account {
 friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);
 private:
  static constexpr const char *def_name = "Unknown";
  static constexpr double def_balance = 0.0;
  static constexpr double def_interest_rate = 0.0;
  static constexpr double bonus = 50.0;
  static constexpr double bonus_threshold = 5000.0;
  static constexpr int max_withdraw = 3;
  static constexpr int max_withdraw_percent = 20.0;
 protected:
  int num_withdraw;
 public:
  Trust_Account(std::string name = def_name, double balance = def_balance, double interest_rate = def_interest_rate);

  bool deposit(double amount);
  bool withdraw(double amount);
};

#endif //CPP_TUTORIAL_S15_CHALLENGE_TRUST_ACCOUNT_H_
