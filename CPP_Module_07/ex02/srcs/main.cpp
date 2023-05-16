/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:03:19 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/16 10:48:44 by fluchten         ###   ########.fr       */
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

/* #define MAX_VAL 750
int main(int, char**)
{
    int * a = new int();
    std::cout << "value of a: " << *a << std::endl;
    delete a;

    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    std::srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = std::rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        tmp[3] = -9;
        Array<int> test(tmp);
        test[3] = 66;
        std::cout << numbers.size() << " numbers[3] = " << numbers[3] << ", " << tmp.size() << " tmp[3] = " << tmp[3] << ", " << test.size() << " test[3] = " << test[3] << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
} */
