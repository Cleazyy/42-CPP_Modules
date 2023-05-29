/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:34:50 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/29 09:01:39 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	if (ac < 2) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}

	for (int i = 1; av[i]; i++) {
		std::string input = av[i];
		for (size_t j = 0; j < input.length(); j++) {
			if (std::islower(input[j])) {
				input[j] = std::toupper(input[j]);
			}
		}
		std::cout << input;
	}
	std::cout << std::endl;

	return (0);
}
