// set::find
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
  set<int>::iterator it;

  // set some initial values:
  for (int i=1; i<=5; i++)
    myset.insert(i*10);    // set: 10 20 30 40 50
print("myset = ", myset);

std::cout << "myset.find(20) and put it in iterator it" << std::endl; 
  it=myset.find(20);
std::cout << "myset.erase(it)" << std::endl;
  myset.erase (it);
std::cout << "myset.erase(myset.find(40))" << std::endl;
  myset.erase (myset.find(40));

  std::cout << "myset contains:";
  for (it=myset.begin(); it!=myset.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}