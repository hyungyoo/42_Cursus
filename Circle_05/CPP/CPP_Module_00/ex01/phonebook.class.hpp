/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:57:18 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/12/11 02:13:17 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

class	Phonebook
{
	public:
		Phonebook();
		~Phonebook();
		void 		loop();

	private:
		Contact	NewContact[8];
		std::string	CheckValue(std::string question) const;
		void		AddContact(int *NumContact);
		void		SearchContact(void) const;
		void		PutHeaderSearch(void) const;
		void		PutAllInfo(Contact EachContact, int index) const;
		std::string	GetFirstName(Contact EachContact) const;
		std::string	GetLastName(Contact EachContact) const;
		std::string	GetNickName(Contact EachContact) const;
		bool		CheckIndex(std::string str) const;
		void		PutContactInfo(std::string str) const;
};

#endif
