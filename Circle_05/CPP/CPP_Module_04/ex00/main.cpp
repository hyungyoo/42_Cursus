#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"

int	main(void)
{
	std::cout << "=====animal constuctor=====" << std::endl;
	const Animal* meta = new Animal();
	std::cout << "=====Dog constuctor=====" << std::endl;
	const Animal* j = new Dog();
	std::cout << "=====Cat constuctor=====" << std::endl;
	const Animal* i = new Cat();
	std::cout << "=====Dog type=====" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << "=====Cat type=====" << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << "=====Cat make sound=====" << std::endl;
	i->makeSound(); //will output the cat sound!
	std::cout << "=====Dog make sound=====" << std::endl;
	j->makeSound();
	std::cout << "=====animal make sound=====" << std::endl;
	meta->makeSound(); //test.makeSound();
	std::cout << "=====animal destructor=====" << std::endl;
	delete meta;
	std::cout << "=====Dog destructor=====" << std::endl;
	delete j;
	std::cout << "=====Cat destructor=====" << std::endl;
	delete i;
	return (0);
}
