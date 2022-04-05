#ifndef CPP_TUTORIAL_S18_CHALLENGE_SRC_ILLIGALBALANCEEXCEPTION_H_
#define CPP_TUTORIAL_S18_CHALLENGE_SRC_ILLEGALBALANCEEXCEPTION_H_

#include <exception>

class IllegalBalanceException : public std::exception {
 public:
  IllegalBalanceException() noexcept = default;
  ~IllegalBalanceException() = default;
  virtual const char* what() const noexcept {
	return "Illegal balance exception";
  }
};

#endif //CPP_TUTORIAL_S18_CHALLENGE_SRC_ILLIGALBALANCEEXCEPTION_H_
