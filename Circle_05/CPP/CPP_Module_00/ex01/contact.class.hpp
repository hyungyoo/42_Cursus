#ifndef CONTACT_H
# define CONTACT_H

class	Contact
{
	public:
		Contact();
		~Contact();
		
		void SetContact(std::string	first_name, std::string	last_name,
			std::string	nick_name, std::string	phone_number, std::string	darkest_secret);
		std::string	GetFirstName(void) const;
		std::string	GetLastName(void) const;
		std::string	GetNickName(void) const;
		std::string	GetPhoneNumber(void) const;
		std::string	GetDarkestSecret(void) const;

	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;
		std::string	phone_number;
		std::string	darkest_secret;
};

#endif
