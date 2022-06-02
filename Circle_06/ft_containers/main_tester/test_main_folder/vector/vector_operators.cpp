// vector comparisons
#include <iostream>
#include <vector>

#include "../main.hpp"

int main ()
{
	{
		vector<int> foo (3,100);   // three ints with a value of 100
		
		std::cout << "foo contains" << std::endl;
		for (size_t i = 0; i < foo.size(); i++)
			std::cout << foo[i] << " ";
		std::cout << std::endl;

		vector<int> bar (2,200);   // two ints with a value of 200

		std::cout << "bar contains" << std::endl;
		for (size_t i = 0; i < bar.size(); i++)
			std::cout << bar[i] << " ";
		std::cout << std::endl;

		if (foo==bar) std::cout << "foo and bar are equal\n";
		if (foo!=bar) std::cout << "foo and bar are not equal\n";
		if (foo< bar) std::cout << "foo is less than bar\n";
		if (foo> bar) std::cout << "foo is greater than bar\n";
		if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
		if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
		std::cout << std::endl;
	}
	{
		std::vector<int> alice;
		for (size_t i = 1; i < 4; i++)
			alice.push_back(i);
		std::cout << "alice contains" << std::endl;
		for (size_t i = 0; i < alice.size(); i++)
			std::cout << alice[i] << " ";
		std::cout << std::endl;
			
		std::vector<int> bob;
		for (size_t i = 7; i < 11; i++)
			bob.push_back(i);
		std::cout << "bob contains" << std::endl;
		for (size_t i = 0; i < bob.size(); i++)
			std::cout << bob[i] << " ";
		std::cout << std::endl;
		
		std::vector<int> eve;
		for (size_t i = 1; i < 4; i++)
			eve.push_back(i);
		std::cout << "eve contains" << std::endl;
		for (size_t i = 0; i < eve.size(); i++)
			std::cout << eve[i] << " ";
		std::cout << std::endl;
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

  return 0;
}