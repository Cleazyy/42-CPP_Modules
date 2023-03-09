/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:08:54 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/09 22:29:13 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	main(void)
{
	PhoneBook	PhoneBook;
	std::string	cmd;

	while (1)
	{
		std::cout << MSG_PHONEBOOK;
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
			PhoneBook.addContact();
		if (cmd == "SEARCH")
			PhoneBook.searchContact();
		if (cmd == "EXIT")
			break;
	}
	return (0);
}