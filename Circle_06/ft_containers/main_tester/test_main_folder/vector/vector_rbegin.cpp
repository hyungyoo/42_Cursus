#include <iostream>
#include <vector>

#include "../main.hpp"

int main ()
{
  vector<int> myvector (5);  // 5 default-constructed ints

  int i=0;

  vector<int>::reverse_iterator rit = myvector.rbegin();
  for (; rit!= myvector.rend(); ++rit)
    *rit = ++i;

  std::cout << "myvector contains:";
  for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}