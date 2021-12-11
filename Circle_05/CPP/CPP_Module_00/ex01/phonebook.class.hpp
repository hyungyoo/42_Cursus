/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:57:18 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/12/11 01:24:33 by hyungyoo         ###   ########.fr       */
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
		void		AddContact(int *NumContact);
		void		SearchContact(void);
		void		PutHeaderSearch(void);
		void		PutAllInfo(Contact EachContact, int index);
		std::string	GetFirstName(Contact EachContact);
		std::string	GetLastName(Contact EachContact);
		std::string	GetNickName(Contact EachContact);
		bool		CheckIndex(std::string str);
		void		PutContactInfo(std::string str);
};

#endif
