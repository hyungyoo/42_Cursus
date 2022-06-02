// set::clear
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

  myset.insert (100);
  myset.insert (200);
  myset.insert (300);

  std::cout << "myset contains:";
  for (set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

    std::cout << "myset.clear()" << std::endl;
  myset.clear();
  std::cout << "myset insert 1101, 2202" << std::endl;
  myset.insert (1101);
  myset.insert (2202);

  std::cout << "myset contains:";
  for (set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}