#ifndef CPP_TUTORIAL_S16_CHALLENGE_CHECKING_ACCOUNT_H_
#define CPP_TUTORIAL_S16_CHALLENGE_CHECKING_ACCOUNT_H_

#include <iostream>
#include "Account.h"

class Checking_Account : public Account {
 private:
  static constexpr const char *def_name = "Unknown";
  static constexpr double def_balance = 0.0;
  static constexpr double def_fee = 1.5;
 protected:
  double fee;
 public:
  Checking_Account(std::string name = def_name, double balance = def_balance, double fee = def_fee);
  virtual ~Checking_Account() {};

  virtual bool withdraw(double amount) override;
  virtual bool deposit(double amount) override;
  virtual void print(std::ostream &os) const override;
};

#endif //CPP_TUTORIAL_S16_CHALLENGE_CHECKING_ACCOUNT_H_
