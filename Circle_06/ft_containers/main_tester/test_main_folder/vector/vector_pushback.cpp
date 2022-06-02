//vector::push_back
#include <iostream>
#include <vector>

#include "../main.hpp"

int main()
{
    vector<int> 	vec;

	std::cout << " * before vector push back * " << std::endl;
	std::cout << "empty?	: " << vec.empty() << std::endl;
	std::cout << std::endl;

	for(size_t i = 0; i < 5; i++)
		vec.push_back(i);

	std::cout << " * after vector push back * " << std::endl;
	std::cout << "empty?	: " << vec.empty() << std::endl;

    std::cout << "vector contains: ";
    for(size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
    std::cout << std::endl;

    return (0);
}