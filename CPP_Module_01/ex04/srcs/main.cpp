/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:38:12 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/29 09:13:35 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.hpp"

int	main(int ac, char **av)
{
	if (ac != 4) {
		std::cout << "Error: wrong number of args." << std::endl;
		return (1);
	}
	std::string	file = av[1];
	std::string	s1 = av[2];
	std::string	s2 = av[3];

	File	File(file);
	if (File.read() != 0)
		return (1);
	File.replace(s1, s2);
	if (File.create() != 0)
		return (1);

	return (0);
}
