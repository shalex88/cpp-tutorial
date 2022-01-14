#ifndef CPP_TUTORIAL_S14_CHALLENGE_MYSTRING_H_
#define CPP_TUTORIAL_S14_CHALLENGE_MYSTRING_H_

class Mystring {
  // Overloaded operators - global functions
  friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
  friend std::istream &operator>>(std::istream &in, Mystring &rhs);

 private:
  char *str;
 public:
  Mystring(); // No-args constructor
  Mystring(const char *s); // Overloaded constructor
  Mystring(const Mystring &source); // Copy constructor - shallow
  Mystring(Mystring &&source) noexcept; // Move constructor
  ~Mystring(); // Destructor

  // Overloaded assignment operators - member methods
  Mystring &operator=(const Mystring &rhs) noexcept; // Copy assignment - deep
  Mystring &operator=(Mystring &&rhs) noexcept; // Move assignment

  // Display method
  void display() const;

  // Getters
  size_t get_length() const;
  const char *get_str() const;

  // Overloaded operator - member methods
  bool  operator==(const Mystring &rhs) const; // Equals
  bool  operator!=(const Mystring &rhs) const; // Not equals
  bool   operator<(const Mystring &rhs) const; // Less than (length)
  bool   operator>(const Mystring &rhs) const; // Greater than (length)
  Mystring  operator+(const Mystring &rhs) const;  // Concatenate
  Mystring  &operator+=(const Mystring &rhs);  // Concatenate and assign
  Mystring  operator*(int n) const; // Repeat n times
  Mystring  &operator*=(int n); // Repeat and assign
  Mystring  operator-();  // Make lowercase
  Mystring  &operator--();  // Make lowercase and assign
  Mystring operator+() ; // Make uppercase
  Mystring &operator++() ; // Make uppercase and assign
};

#endif //CPP_TUTORIAL_S14_CHALLENGE_MYSTRING_H_
