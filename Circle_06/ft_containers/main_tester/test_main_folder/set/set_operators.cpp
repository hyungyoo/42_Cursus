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

int main()
{
	set<int> alice;
	alice.insert(1);
	alice.insert(2);
	alice.insert(3);
    print("alice set contains: ", alice);
	
    set<int> bob;
	bob.insert(4);
    bob.insert(5);
    bob.insert(6);
	bob.insert(7);
	print("bob set contains: ", bob);

	set<int> eve;
	eve.insert(1);
    eve.insert(2);
    eve.insert(3);
    print("eve set contains: ", eve);
    std::cout << std::endl;

	std::cout << std::boolalpha;
 
	// Compare non equal containers
	std::cout << "alice == bob returns " << (alice == bob) << '\n';
	std::cout << "alice != bob returns " << (alice != bob) << '\n';
	std::cout << "alice <  bob returns " << (alice < bob) << '\n';
	std::cout << "alice <= bob returns " << (alice <= bob) << '\n';
	std::cout << "alice >  bob returns " << (alice > bob) << '\n';
	std::cout << "alice >= bob returns " << (alice >= bob) << '\n';
 
	std::cout << '\n';
 
	// Compare equal containers
	std::cout << "alice == eve returns " << (alice == eve) << '\n';
	std::cout << "alice != eve returns " << (alice != eve) << '\n';
	std::cout << "alice <  eve returns " << (alice < eve) << '\n';
	std::cout << "alice <= eve returns " << (alice <= eve) << '\n';
	std::cout << "alice >  eve returns " << (alice > eve) << '\n';
	std::cout << "alice >= eve returns " << (alice >= eve) << '\n';
}