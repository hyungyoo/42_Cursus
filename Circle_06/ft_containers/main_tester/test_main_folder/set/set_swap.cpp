// swap sets
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
  int myints[]={12,75,10,32,20,25};
  std::cout << "myints contains: ";
  for (size_t i = 0; i < 6; i++)
    std::cout << myints[i] << " ";
std::cout << std::endl;


  set<int> first (myints,myints+3);     // 10,12,75
print("first = ", first);

  set<int> second (myints+3,myints+6);  // 20,25,32
print("second = ", second);

std::cout << "first.swap(second)" << std::endl;
  first.swap(second);

  std::cout << "first contains:";
  for (set<int>::iterator it=first.begin(); it!=first.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::cout << "second contains:";
  for (set<int>::iterator it=second.begin(); it!=second.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}