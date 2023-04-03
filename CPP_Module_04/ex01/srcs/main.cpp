/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:03:37 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/02 15:01:26 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void	animalTests(void)
{
	const Animal* base = new Animal();
	const Animal* cat = new Cat();
	const Animal* dog = new Dog();

	std::cout << std::endl;

	std::cout << "base = " << base->getType() << std::endl;
	std::cout << "cat = " << cat->getType() << std::endl;
	std::cout << "dog = " << dog->getType() << std::endl;

	std::cout << std::endl;

	base->makeSound();
	cat->makeSound();
	dog->makeSound();

	std::cout << std::endl;

	delete base;
	delete cat;
	delete dog;
}

void	wrongAnimalTests(void)
{
	const WrongAnimal* wrongBase = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << std::endl;

	std::cout << "wrongBase = " << wrongBase->getType() << std::endl;
	std::cout << "wrongCat = " << wrongCat->getType() << std::endl;

	std::cout << std::endl;

	wrongBase->makeSound();
	wrongCat->makeSound();

	std::cout << std::endl;

	delete wrongBase;
	delete wrongCat;
}

int	main(void)
{
	std::cout << "\033[1;32m" << "[ ANIMAL ]" << "\033[0m" << std::endl;
	animalTests();

	std::cout << std::endl;

	std::cout << "\033[1;31m" << "[ WRONG ANIMAL ]" << "\033[0m" << std::endl;
	wrongAnimalTests();

	return (0);
}