/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:34:50 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/25 20:17:55 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static int	print_error(const char *str)
{
	std::cerr << str << std::endl;
	return (1);
}

static void	to_upper(char *str)
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	}
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return (print_error("* LOUD AND UNBEARABLE FEEDBACK NOISE *"));
	for (int i = 1; av[i]; i++)
	{
		to_upper(av[i]);
		std::cout << av[i];
	}
	std::cout << std::endl;
	return (0);
}
