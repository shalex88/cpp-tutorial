#ifndef CPP_TUTORIAL_S15_CHALLENGE_ACCOUNT_H_
#define CPP_TUTORIAL_S15_CHALLENGE_ACCOUNT_H_

class Account {
 friend std::ostream &operator<<(std::ostream &os, const Account &account);
 private:
  static constexpr const char *def_name = "Unknown";
  static constexpr double def_balance = 0.0;
 protected:
  std::string name;
  double balance;
 public:
  Account(std::string name = def_name, double balance = def_balance);

  bool deposit(double amount);
  bool withdraw(double amount);
  double get_balance() const;
};



#endif //CPP_TUTORIAL_S15_CHALLENGE_ACCOUNT_H_
