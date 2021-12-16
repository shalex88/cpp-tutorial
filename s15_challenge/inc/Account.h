#ifndef CPP_TUTORIAL_S15_CHALLENGE_ACCOUNT_H_
#define CPP_TUTORIAL_S15_CHALLENGE_ACCOUNT_H_

class Account {
 friend std::ostream &operator<<(std::ostream &os, const Account &account);
 private:
  static constexpr const char *def_name = "Account";
  static constexpr double def_balance = 0.0;
 protected:
  double balance;
  std::string name;
//  Account(double balance, std::string name);
 public:
  Account(std::string name = def_name, double balance = def_balance);
//  Account(double balance);

  void deposit(double amount);
  void withdraw(double amount);
};



#endif //CPP_TUTORIAL_S15_CHALLENGE_ACCOUNT_H_
