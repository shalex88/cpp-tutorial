#ifndef CPP_TUTORIAL_S16_CHALLENGE_INC_I_PRINTABLE_H_
#define CPP_TUTORIAL_S16_CHALLENGE_INC_I_PRINTABLE_H_

#include <iostream>

class I_Printable {
  friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj);
 public:
  virtual void print(std::ostream &os) const = 0;
  virtual ~I_Printable() {};
};

#endif //CPP_TUTORIAL_S16_CHALLENGE_INC_I_PRINTABLE_H_
