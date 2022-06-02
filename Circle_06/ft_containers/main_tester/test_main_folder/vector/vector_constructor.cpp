#include <iostream>
#include <string>

#include "../main.hpp"

template<typename T>
std::ostream& operator<<(std::ostream& s, const vector<T>& v) 
{
    s.put('[');
    char comma[3] = {'\0', ' ', '\0'};
    for (unsigned i = 0; i < v.size(); i++) {
        s << comma << v[i];
        comma[0] = ',';
    }
    return s << ']';
}

int main ()
{
	{
		// constructors used in the same order as described above:
		vector<int> first;                                // empty vector of ints
		vector<int> second (4,100);                       // four ints with value 100
		vector<int> third (second.begin(),second.end());  // iterating through second
		vector<int> fourth (third);                       // a copy of third

		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {16,2,77,29};
		std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

		std::cout << "The contents of fifth are:";
		for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}

	{
		vector<std::string> words1;
		std::cout << "words1: " << words1 << '\n';
		words1.push_back("hello");
		words1.push_back("world");
		words1.push_back("test");
	
		// words2 == words1
		vector<std::string> words2(words1.begin(), words1.end());
		std::cout << "words2: " << words2 << '\n';
	
		// words3 == words1
		vector<std::string> words3(words1);
		std::cout << "words3: " << words3 << '\n';
	
		// words4 is {"Mo", "Mo", "Mo", "Mo", "Mo"}
		vector<std::string> words4(5, "Mo");
		std::cout << "words4: " << words4 << '\n';
	}

	return 0;
}