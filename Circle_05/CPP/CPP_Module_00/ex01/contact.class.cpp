#include "main.h"

Contact::Contact()
{
	/*
	this->first_name = NULL;
	this->last_name = NULL;
	this->nick_name = NULL;
	this->phone_number = NULL;
	this->darkest_secret = NULL;
	*/
}
Contact::~Contact()
{
	//std::cout << "Closed new Contact" << std::endl;
}

std::string	Contact::GetFirstName(void) const
{
	return (this->first_name);
}

std::string	Contact::GetLastName(void) const
{
	return (this->last_name);
}

std::string	Contact::GetNickName(void) const
{
	return (this->nick_name);
}

std::string	Contact::GetPhoneNumber(void) const
{
	return (this->phone_number);
}

std::string	Contact::GetDarkestSecret(void) const
{
	return (this->darkest_secret);
}

void	Contact::SetContact(std::string	first_name,
				 std::string	last_name,
				 std::string	nick_name,
				 std::string	phone_number,
				 std::string	darkest_secret)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->nick_name = nick_name;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}
