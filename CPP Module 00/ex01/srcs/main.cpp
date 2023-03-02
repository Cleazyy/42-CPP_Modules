/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:08:54 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/25 20:18:29 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	main(void)
{
	std::string	cmd;

	while (1)
	{
		std::cout << "PhoneBook: ";
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
			break;
		if (cmd == "SEARCH")
			break;
		if (cmd == "EXIT")
			break;
	}
	return (0);
}