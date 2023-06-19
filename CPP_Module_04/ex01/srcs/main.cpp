/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:03:37 by fluchten          #+#    #+#             */
/*   Updated: 2023/06/19 10:09:36 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::cout << "\033[1;32m" << "[ CONSTRUCTOR ]" << "\033[0m" << std::endl;
	const Animal* cat = new Cat();
	const Animal* dog = new Dog();
	std::cout << std::endl;

	std::cout << "\033[1;31m" << "[ DESTRUCTOR ]" << "\033[0m" << std::endl;
	delete cat;
	delete dog;
	std::cout << std::endl;

	std::cout << "\033[1;32m" << "[ TAB CONSTRUCTOR ]" << "\033[0m" << std::endl;
	const Animal* animals[2] = {new Cat(), new Dog()};
	std::cout << std::endl;

	std::cout << "\033[1;31m" << "[ TAB DESTRUCTOR ]" << "\033[0m" << std::endl;
	for (int i = 0; i < 2; i++)
		delete animals[i];

	return (0);
}
