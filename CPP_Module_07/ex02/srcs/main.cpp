/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:03:19 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/15 20:19:56 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

template<typename T>
void	print_array(Array<T> &array, const std::string name)
{
	std::cout << "size = " << array.size() << std::endl;
	for (unsigned int i = 0; i < array.size(); i++) {
		std::cout << name << "[" << i << "] = " << array[i] << std::endl;
	}
}

int	main(void)
{
	std::cout << "-- -[ intArray ]- --" << std::endl;
	Array<int> intArray(3);
	intArray[0] = 19;
	intArray[1] = 42;
	intArray[2] = 21;
	print_array(intArray, "intArray");
	std::cout << std::endl;

	std::cout << "-- -[ intArray copy constructor ]- --" << std::endl;
	Array<int> copyIntArray(intArray);
	print_array(copyIntArray, "copyIntArray");
	std::cout << std::endl;

	std::cout << "-- -[ charArray ]- --" << std::endl;
	Array<char> charArray(4);
	charArray[0] = 'a';
	charArray[1] = 'b';
	charArray[2] = 'c';
	charArray[3] = 'd';
	print_array(charArray, "charArray");
	std::cout << std::endl;

	std::cout << "-- -[ charArray copy assignment operator ]- --" << std::endl;
	Array<char> assignmentcharArray = charArray;
	print_array(assignmentcharArray, "assignmentcharArray");
	std::cout << std::endl;

	try {
		std::cout << "-- -[ stringArray ]- --" << std::endl;
		Array<std::string> stringArray(2);
		stringArray[0] = "Hello";
		stringArray[1] = "World";
		stringArray[2] = "!";
		print_array(stringArray, "stringArray");
	} catch (std::exception &e){
		std:: cout << e.what() << std::endl;
	}

	return (0);
}
