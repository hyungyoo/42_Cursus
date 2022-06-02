#include <iostream>
#include "../main.hpp"
 
int main()
{
	map<int, char> alice;
	alice[1] = 'a';
	alice[2] = 'b';
	alice[3] = 'c';

	std::cout << "alice contains" << std::endl;
    for (map<int, char>::iterator it = alice.begin(); it != alice.end(); it++)
        std::cout << it->first << " : " << it->second << std::endl;
    std::cout << std::endl;
	
	map<int, char> bob;
	bob[7] = 'Z';
    bob[8] = 'Y';
    bob[9] = 'X';
	bob[10] = 'W';
	std::cout << "bob contains" << std::endl;
    for (map<int, char>::iterator it = bob.begin(); it != bob.end(); it++)
        std::cout << it->first << " : " << it->second << std::endl;
    std::cout << std::endl;
   
	map<int, char> eve;
	eve[1] = 'a';
    eve[2] = 'b';
    eve[3] = 'c';
    std::cout << "eve contains" << std::endl;
    for (map<int, char>::iterator it = eve.begin(); it != eve.end(); it++)
        std::cout << it->first << " : " << it->second << std::endl;
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