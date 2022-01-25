#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

#include <iostream>

class Data
{
	private:
		const std::string _nom;
		const std::string _prenom;
		int _age;
	
	public:
		Data(void);
		Data(const std::string nom, const std::string prenom, int age);
		~Data(void);
		Data(Data const &copy);
		Data &operator=(Data const &rhs);

		void	updateAge(int new_age);

		const std::string	&getNom(void) const;
		const std::string &getPrenom(void) const;
		int	getAge(void) const;
};

std::ostream	&operator<<(std::ostream &o, Data const &rhs);

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif
