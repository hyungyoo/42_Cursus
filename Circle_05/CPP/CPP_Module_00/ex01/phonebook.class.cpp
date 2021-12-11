#include "main.h"

/*
 * constructo
 */
Phonebook::Phonebook()
{
	std::cout << "Open Phonebook" << std::endl;
}

/*
 * destructor
 */
Phonebook::~Phonebook()
{
	std::cout << "Closed Phonebook" << std::endl;
}

/*
 * ADD
 * contruct --> non, parceque l'on a deja fait construct for 8
 */
void	Phonebook::AddContact(int	*NumContact)
{
	std::string	first_name;
	std::string	last_name;
	std::string	nick_name;
	std::string	phone_number;
	std::string	darkest_secret;

	std::cout << "first_name: ";
	std::getline(std::cin, first_name);
	std::cout << "last_name: ";
	std::getline(std::cin, last_name);
	std::cout << "nick_name: ";
	std::getline(std::cin, nick_name);
	std::cout << "phone number: ";
	std::getline(std::cin, phone_number);
	std::cout << "darkest secret: ";
	std::getline(std::cin, darkest_secret);
	NewContact[*NumContact % CONTACT_MAX].SetContact(first_name, last_name, nick_name, phone_number, darkest_secret);
	*NumContact += 1;
}

/*
 * SEARCH
 */
std::string	Phonebook::GetFirstName(Contact EachContact)
{
	if (EachContact.GetFirstName().length() >= 10)
		return (EachContact.GetFirstName().substr(0, 9).append("."));
	else
		return (EachContact.GetFirstName());
}

std::string	Phonebook::GetLastName(Contact EachContact)
{
	if (EachContact.GetLastName().length() >= 10)
		return (EachContact.GetLastName().substr(0, 9).append("."));
	else
		return (EachContact.GetLastName());
}

std::string	Phonebook::GetNickName(Contact EachContact)
{
	if (EachContact.GetNickName().length() >= 10)
		return (EachContact.GetNickName().substr(0, 9).append("."));
	else
		return (EachContact.GetNickName());
}

void	Phonebook::PutHeaderSearch(void)
{
	std::cout << "|";
	std::cout << std::setw(10) << "index";
	std::cout << "|";
	std::cout << std::setw(10) << "first name";
	std::cout << "|";
	std::cout << std::setw(10) << "last name";
	std::cout << "|";
	std::cout << std::setw(10) << "nick name";
	std::cout << "|" << std::endl;
}

void	Phonebook::PutAllInfo(Contact EachContact, int index)
{
	std::cout << "|";
	std::cout << std::setw(10) << index;
	std::cout << "|";
	std::cout << std::setw(10) << GetFirstName(EachContact);
	std::cout << "|";
	std::cout << std::setw(10) << GetLastName(EachContact);
	std::cout << "|";
	std::cout << std::setw(10) << GetNickName(EachContact);
	std::cout << "|" << std::endl;
}

bool	Phonebook::CheckIndex(std::string str)
{
	if (str.length() >= 2)
		return (0);
	if (std::isdigit(str[0]))
		if (!NewContact[std::stoi(str)].GetFirstName().empty())
			return (1);
	return (0);
}

void	Phonebook::PutContactInfo(std::string str)
{
	int	index;

	index = std::stoi(str);
	std::cout << "first name: " << NewContact[index].GetFirstName() << std::endl;
	std::cout << "last name: " << NewContact[index].GetLastName() << std::endl;
	std::cout << "nick name: " << NewContact[index].GetNickName() << std::endl;
	std::cout << "phone number: " << NewContact[index].GetPhoneNumber() << std::endl;
	std::cout << "darkest secret: " << NewContact[index].GetDarkestSecret() << std::endl;
}

void	Phonebook::SearchContact(void)
{
	int			i;
	std::string	str;

	if (NewContact[0].GetFirstName().empty())
	{
		std::cout << "We do not have any contact information." << std::endl;
		return ;
	}
	PutHeaderSearch();
	i = 0;
	while (i < 8)
	{
		if (!NewContact[i].GetFirstName().empty())
			PutAllInfo(NewContact[i], i);
		else
			break ;
		i++;
	}
	while (42)
	{
		std::cout << "Enter index! :" << std::endl;	
		if (std::getline(std::cin, str).eof())
			std::exit(0);
		else if (CheckIndex(str))
			return (PutContactInfo(str));
		else
			std::cout << "Invalid index" << std::endl;
	}
}

/*
 * main for EXIT, ADD and SEARCH
 */
void	Phonebook::loop()
{
	std::string	str;
	int			NumContact;

	NumContact = 0;
	while (42)
	{
		std::cout << "Enter ADD, SEARCH or EXIT" << std::endl;
		if (std::getline(std::cin, str).eof())
			return ;
		else if (str == "EXIT")
			return ;
		else if (str == "ADD")
			AddContact(&NumContact);
		else if (str == "SEARCH")
			SearchContact();
		else
			std::cout << "No matching command found." << std::endl;
	}
}