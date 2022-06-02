#include <iostream>
#include <vector>

#include "../main.hpp"

int main ()
{
  vector<int> foo (3,0);
  vector<int> bar (5,0);

  bar = foo;
  foo = vector<int>();

  std::cout << "Size of foo: " << int(foo.size()) << '\n';
  std::cout << "Size of bar: " << int(bar.size()) << '\n';
  return 0;
}