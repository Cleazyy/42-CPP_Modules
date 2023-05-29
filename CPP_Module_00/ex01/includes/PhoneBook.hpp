/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:17:27 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/29 08:57:43 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <cstring>
# include "Contact.hpp"

# define MSG_PHONEBOOK "\033[1;36mPhoneBook: \033[0m"
# define MSG_ADD "\033[1;32mADD: \033[0m"
# define MSG_SEARCH "\033[1;33mSEARCH: \033[0m"
# define MSG_ERROR "\033[1;31mERROR: \033[0m"
# define MSG_SEPARTOR "|----------|----------|----------|----------|"

class PhoneBook
{
	private:
		Contact _contact[8];

		void _printHeader(void);
		void _printList(void);
		bool _inputOnlyDigits(const std::string &str);

	public :
		PhoneBook(void);
		~PhoneBook(void);

		void addContact(void);
		void searchContact(void);
};

#endif
