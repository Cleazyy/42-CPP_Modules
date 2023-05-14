/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:03:19 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/14 16:52:19 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

template<typename T>
void print(T &value)
{
	std::cout << "[" << value << "]" << std::endl;
}

int	main(void)
{
	int intArray[3] = {19, 42, 21};
	char charArray[3] = {'a', 'b', 'c'};

	iter(intArray, 3, print<int>);
	std::cout << std::endl;
	iter(charArray, 3, print<char>);

	return (0);
}
