// set::equal_elements
#include <iostream>
#include "../main.hpp"

void print(std::string const comment, set<int> const& container)
{
    size_t size = container.size();
    std::cout << comment << "{ ";
	for (set<int>::iterator it = container.begin(); it != container.end(); it++)
        std::cout << *it << (--size ? ", " : " ");
    std::cout << "}\n";
}


int main ()
{
  set<int> myset;

  for (int i=1; i<=5; i++)
    myset.insert(i*10);   // myset: 10 20 30 40 50
print("myset = ", myset);

  pair<set<int>::const_iterator,set<int>::const_iterator> ret;
  ret = myset.equal_range(30);

  std::cout << "the lower bound points to: " << *ret.first << '\n';
  std::cout << "the upper bound points to: " << *ret.second << '\n';

  return 0;
}