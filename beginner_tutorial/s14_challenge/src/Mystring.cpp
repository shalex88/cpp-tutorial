#include <cstring>
#include <iostream>
#include "Mystring.h"

//no-args constructor
Mystring::Mystring()
	: str{nullptr} {
  str = new char[1];
  *str = '\0';
  std::cout << "no-args constructor" << std::endl;
}

//overloaded constructor
Mystring::Mystring(const char *s)
	: str{nullptr} {
  if (s == nullptr) {
	str = new char[1];
	*str = '\0';
  } else {
	str = new char[std::strlen(s) + 1];
	std::strcpy(str, s);
  }
  std::cout << "overloaded constructor" << std::endl;
}

//copy constructor - shallow
Mystring::Mystring(const Mystring &source)
	: str{nullptr} {
  str = new char[std::strlen(source.str) + 1];
  std::strcpy(str, source.str);
  std::cout << "copy constructor - shallow" << std::endl;
}

//move constructor
Mystring::Mystring(Mystring &&source) noexcept
	: str{source.str} {
  source.str = nullptr;
  std::cout << "move constructor" << std::endl;
}

//destructor
Mystring::~Mystring() {
  delete[] str;
}

//copy assignment - deep
Mystring &Mystring::operator=(const Mystring &rhs) noexcept {
  if (this == &rhs) //check for self-assignment
	return *this;

  delete[] str; //deallocate current storage
  str = new char[std::strlen(rhs.str) + 1]; //allocate new storage
  std::strcpy(str, rhs.str);

  std::cout << "copy assignment - deep" << std::endl;

  return *this;
}

//move assignment
Mystring &Mystring::operator=(Mystring &&rhs) noexcept {
  if (this == &rhs) //check for self-assignment
	return *this;

  delete[] str; //deallocate current storage
  str = rhs.str; //steal the pointer
  rhs.str = nullptr; //null the rhs object

  std::cout << "move assignment" << std::endl;

  return *this;
}

//display method
void Mystring::display() const {
  std::cout << str << " : " << get_length() << std::endl;
}

//getters
size_t Mystring::get_length() const {
  return std::strlen(str);
}

const char *Mystring::get_str() const {
  return str;
}

// overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs)
{
  os << rhs.str;
  return os;
}

// overloaded extraction operator
std::istream &operator>>(std::istream &is, Mystring &rhs)
{
  std::string buff;
  is >> buff;
  rhs = Mystring{buff.c_str()};
  return is;
}

// Equals
bool   Mystring::operator==(const Mystring &rhs) const
{
  return ( std::strcmp(str, rhs.str) == 0);
}

// Not equals
bool   Mystring::operator!=(const Mystring &rhs) const
{
  return ( std::strcmp(str, rhs.str) != 0);
}

// Less than (length)
bool   Mystring::operator<(const Mystring &rhs) const
{
  return get_length() < rhs.get_length();
}

// Greater than (length)
bool   Mystring::operator>(const Mystring &rhs) const
{
  return get_length() > rhs.get_length();
}

// Concatenate
Mystring  Mystring::operator+(const Mystring &rhs) const
{
  char *buff = new char[strlen(str) + strlen(rhs.str) + 1];
  std::strcpy(buff, str);
  std::strcat(buff, rhs.str);
  Mystring temp {buff};
  delete [] buff;
  return temp;
}

// Concatenate and assign
Mystring  &Mystring::operator+=(const Mystring &rhs)
{
  *this = *this + rhs.str;
  return *this;
}

// Repeat n times
Mystring  Mystring::operator*(int n) const
{
  Mystring temp;
  for (int i {0}; i < n; ++i) {
	temp += *this;
  }
  return temp;
}

// Repeat and assign
Mystring  &Mystring::operator*=(int n)
{
  *this = *this * n;
  return *this;
}

// Make lowercase
Mystring Mystring::operator-()
{
  char *buff = new char[strlen(str) + 1];
  std::strcpy(buff, str);
  for (size_t i {0}; i < strlen(str); ++i) {
	buff[i] = std::tolower(buff[i]);
  }
  Mystring temp {buff};
  delete [] buff;
  return temp;
}

// Make uppercase
Mystring Mystring::operator+()
{
  char *buff = new char[strlen(str) + 1];
  std::strcpy(buff, str);
  for (size_t i {0}; i < strlen(str); ++i) {
	buff[i] = std::toupper(buff[i]);
  }
  Mystring temp {buff};
  delete [] buff;
  return temp;
}

// Make uppercase and assign
Mystring  &Mystring::operator++()
{
  *this = +*this;
  return *this;
}

// Make lowercase and assign
Mystring  &Mystring::operator--()
{
  *this = -*this;
  return *this;
}
