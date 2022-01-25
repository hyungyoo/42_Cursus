#include "Serialization.hpp"

Data::Data(void) : _nom("no_name"), _prenom("no_prenome"), _age(0)
{
}

Data::Data(const std::string nom, const std::string prenom, int age) : _nom(nom), _prenom(prenom), _age(age)
{
}

Data::~Data(void)
{
}

Data::Data(Data const &copy) : _nom(copy.getNom()), _prenom(copy.getPrenom()), _age(copy.getAge())
{
}

Data	&Data::operator=(Data const &rhs)
{
	*(const_cast<std::string*>(&_nom)) = rhs.getNom();
	*(const_cast<std::string*>(&_prenom)) = rhs.getPrenom();
	_age = rhs.getAge();
	return (*this);
}

void	Data::updateAge(int new_age)
{
	this->_age = new_age;
}

const std::string &Data::getNom(void) const
{
	return (this->_nom);
}

const std::string &Data::getPrenom(void) const
{
	return (this->_prenom);
}

int	Data::getAge(void) const
{
	return (this->_age);
}

std::ostream	&operator<<(std::ostream &o, Data const &rhs)
{
	o << "nom: " << rhs.getNom() << std::endl;
	o << "prenom: " << rhs.getPrenom() << std::endl;
	o << "age: " << rhs.getAge() << std::endl;
	return (o);
}

uintptr_t	serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
