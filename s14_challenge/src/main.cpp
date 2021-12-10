#include <iostream>
#include <cstring>

using namespace std;
using std::cout;
using std::endl;

class Mystring {
 private:
  char *str;
 public:
  Mystring(); //no-args constructor
  Mystring(const char *s); //overloaded constructor
  Mystring(const Mystring &source); //copy constructor - shallow
  Mystring(Mystring &&source) noexcept; //move constructor
  Mystring &operator=(const Mystring &rhs) noexcept; //copy assignment - deep
  Mystring &operator=(Mystring &&rhs) noexcept; //move assignment
  ~Mystring(); //destructor
  void display() const;
  size_t get_length() const;
  const char *get_str() const;
};

//no-args constructor
Mystring::Mystring()
	: str{nullptr} {
  str = new char[1];
  *str = '\0';
  cout << "no-args constructor" << endl;
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
  cout << "overloaded constructor" << endl;
}

//copy constructor - shallow
Mystring::Mystring(const Mystring &source)
	: str{nullptr} {
  str = new char[std::strlen(source.str) + 1];
  std::strcpy(str, source.str);
  cout << "copy constructor - shallow" << endl;
}

//move constructor
Mystring::Mystring(Mystring &&source) noexcept
	: str{source.str} {
  source.str = nullptr;
  cout << "move constructor" << endl;
}

//copy assignment - deep
Mystring &Mystring::operator=(const Mystring &rhs) noexcept {
  if (this == &rhs) //check for self-assignment
	return *this;

  delete[] str; //deallocate current storage
  str = new char[std::strlen(rhs.str) + 1]; //allocate new storage
  std::strcpy(str, rhs.str);

  cout << "copy assignment - deep" << endl;

  return *this;
}

//move assignment
Mystring &Mystring::operator=(Mystring &&rhs) noexcept {
  if (this == &rhs) //check for self-assignment
	return *this;

  delete[] str; //deallocate current storage
  str = rhs.str; //steal the pointer
  rhs.str = nullptr; //null the rhs object

  cout << "move assignment" << endl;

  return *this;
}

//destructor
Mystring::~Mystring() {
  delete[] str;
}

void Mystring::display() const {
  cout << str << " : " << get_length() << endl;
}

size_t Mystring::get_length() const {
  return std::strlen(str);
}

const char *Mystring::get_str() const {
  return str;
}

int main() {
  cout << "--- a ---" << endl;
  Mystring a;
  a.display();

  cout <<  endl << "--- b ---" << endl;
  Mystring b("Larry");
  b.display();

  cout << endl << "--- c ---" << endl;
  Mystring c{b};
  c.display();

  cout << endl << "--- d ---" << endl;
  Mystring d;
  d = c;
  b.display();

  cout << endl << "--- e ---" << endl;
  Mystring e;
  e = Mystring{"Alex"};
  e.display();

  cout << endl << "--- f ---" << endl;
  Mystring f {Mystring{"Alex"}};
  f.display();

  return 0;
}
