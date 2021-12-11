#ifndef CONTACT_H
# define CONTACT_H

class	Contact
{
	public:
		Contact();
		~Contact();
		
		void SetContact(std::string	first_name, std::string	last_name,
			std::string	nick_name, std::string	phone_number, std::string	darkest_secret);
		std::string	GetFirstName(void);
		std::string	GetLastName(void);
		std::string	GetNickName(void);
		std::string	GetPhoneNumber(void);
		std::string	GetDarkestSecret(void);

	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;
		std::string	phone_number;
		std::string	darkest_secret;

};

#endif
