#ifndef CPP_TUTORIAL_S16_CHALLENGE_TRUST_ACCOUNT_H_
#define CPP_TUTORIAL_S16_CHALLENGE_TRUST_ACCOUNT_H_

#include <iostream>
#include "Savings_Account.h"

class Trust_Account : public Savings_Account {
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
  virtual ~Trust_Account() {};

  virtual bool deposit(double amount) override;
  virtual bool withdraw(double amount) override;
  virtual void print(std::ostream &os) const override;
};

#endif //CPP_TUTORIAL_S16_CHALLENGE_TRUST_ACCOUNT_H_
