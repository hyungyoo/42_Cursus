#include "Dog.hpp"
#include "WrongDog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"

int	main(void)
{

	std::cout << "=================== animal ===================" << std::endl;
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
	std::cout << std::endl << std::endl;
	std::cout << "=================== Wrong ===================" << std::endl;

	std::cout << "=====Wrong animal constuctor=====" << std::endl;
	const WrongAnimal* Wrongmeta = new WrongAnimal();
	std::cout << "=====Wrong Dog constuctor=====" << std::endl;
	const WrongAnimal* Wj = new WrongDog();
	std::cout << "=====Wrong Cat constuctor=====" << std::endl;
	const WrongAnimal* Wi = new WrongCat();
	std::cout << "=====Wrong Dog type=====" << std::endl;
	std::cout << Wj->getType() << " " << std::endl;
	std::cout << "=====Wrong Cat type=====" << std::endl;
	std::cout << Wi->getType() << " " << std::endl;
	std::cout << "=====Wrong Cat make sound=====" << std::endl;
	Wi->makeSound(); //will output the cat sound!
	std::cout << "=====Wrong Dog make sound=====" << std::endl;
	Wj->makeSound();
	std::cout << "=====Wrong animal make sound=====" << std::endl;
	Wrongmeta->makeSound(); //test.makeSound();
	std::cout << "=====Wrong animal destructor=====" << std::endl;
	delete Wrongmeta;
	std::cout << "=====Wrong Dog destructor=====" << std::endl;
	delete Wj;
	std::cout << "=====Cat destructor=====" << std::endl;
	delete Wi;
	return (0);
}
