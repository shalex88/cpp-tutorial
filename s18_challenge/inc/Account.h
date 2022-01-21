#ifndef CPP_TUTORIAL_S16_CHALLENGE_ACCOUNT_H_
#define CPP_TUTORIAL_S16_CHALLENGE_ACCOUNT_H_

#include "I_Printable.h"

class Account : public I_Printable {
 private:
  static constexpr const char *def_name = "Unknown";
  static constexpr double def_balance = 0.0;
 protected:
  std::string name;
  double balance;
 public:
  Account(std::string name = def_name, double balance = def_balance);
  virtual ~Account() {};

  virtual bool deposit(double amount) = 0;
  virtual bool withdraw(double amount) = 0;
  virtual void print(std::ostream &os) const override;
};

#endif //CPP_TUTORIAL_S16_CHALLENGE_ACCOUNT_H_
