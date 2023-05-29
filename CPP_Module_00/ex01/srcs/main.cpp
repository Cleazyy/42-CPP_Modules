/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:08:54 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/29 08:55:39 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook PhoneBook;
	std::string cmd;

	while (1)
	{
		std::cout << MSG_PHONEBOOK;
		std::getline(std::cin, cmd);
		if (std::cin.eof())
			break ;

		if (cmd == "ADD")
			PhoneBook.addContact();
		if (cmd == "SEARCH")
			PhoneBook.searchContact();
		if (cmd == "EXIT")
			break;
	}

	return (0);
}
