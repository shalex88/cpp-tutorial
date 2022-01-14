#include <iostream>
#include "Mystring.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
  cout << "--- No-arg constructor ---" << endl;
  Mystring a;
  a.display();

  cout <<  endl << "--- Overloaded constructor ---" << endl;
  Mystring b("Larry");
  b.display();

  cout <<  endl << "--- Overloaded stream insertion operator ---" << endl;
  cout << b << endl;

  cout << endl << "--- Copy constructor - shallow ---" << endl;
  Mystring c{b};
  cout << c << endl;

  cout << endl << "--- Move constructor should be used. Optimized out by compilers copy elision (RVO) ---" << endl;
  Mystring d {Mystring{"Alex"}};
  cout << d << endl;

  cout << endl << "--- Copy assignment - deep ---" << endl;
  Mystring e;
  e = c;
  cout << e << endl;

  cout << endl << "--- Move assignment ---" << endl;
  Mystring f;
  f = Mystring{"Alex"};
  cout << f << endl;

  cout << endl << "--- Equality ---" << endl;
  b = "george";
  cout << std::boolalpha;
  cout << (b == c) << endl;
  cout << (b != c) << endl;
  cout << (b < c) << endl;
  cout << (b > c) << endl;

  cout << endl << "--- Concatenate ---" << endl;
  Mystring s1 {"FRANK"};
  s1 = s1 + "*****";
  cout << s1 << endl;

  cout << endl << "--- Concatenate and assign ---" << endl;
  s1 += ".....";
  cout << s1 << endl;

  cout << endl << "--- Repeat n times ---" << endl;
  Mystring s2{"12345"};
  s1 = s2 * 3;
  cout << s1 << endl;

  cout << endl << "--- Repeat and assign ---" << endl;
  Mystring s3{"abcdef"};
  s3 *= 5;
  cout << s3 << endl;

  cout << endl << "--- Make uppercase ---" << endl;
  Mystring s = "Frank";
  ++s;
  cout << s << endl;

  cout << endl << "--- Make lowercase ---" << endl;
  --s;
  cout << s << endl;

  cout << endl << "--- Make uppercase and assign ---" << endl;
  Mystring result;
  result = +s;
  cout << s << endl;
  cout << result << endl;

  cout << endl << "--- Make lowercase and assign ---" << endl;
  s = -result;
  cout << result << endl;
  cout << s << endl;
  return 0;
}
