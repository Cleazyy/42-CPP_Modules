/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:11:10 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/25 16:17:22 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	std::string	input;
	Harl		Harl;

	while (1)
	{
		std::cout << MSG_HARL;
		std::getline(std::cin, input);
		Harl.complain(input);
	}
	return (0);
}