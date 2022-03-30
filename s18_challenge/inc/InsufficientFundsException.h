#ifndef CPP_TUTORIAL_S18_CHALLENGE_INSUFFICIENTFUNDSEXCEPTION_H_
#define CPP_TUTORIAL_S18_CHALLENGE_INSUFFICIENTFUNDSEXCEPTION_H_

#include <exception>

class InsufficientFundsException : public std::exception {
 public:
  InsufficientFundsException() noexcept = default;
  ~InsufficientFundsException() = default;
  virtual const char *what() const noexcept {
	return "Insufficient funds exception";
  }
};

#endif //CPP_TUTORIAL_S18_CHALLENGE_INSUFFICIENTFUNDSEXCEPTION_H_
