/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:03:37 by fluchten          #+#    #+#             */
/*   Updated: 2023/06/19 10:15:58 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	std::cout << "\033[1;32m" << "[ CONSTRUCTOR ]" << "\033[0m" << std::endl;
	const AAnimal* cat = new Cat();
	const AAnimal* dog = new Dog();
	std::cout << std::endl;

	std::cout << "\033[1;31m" << "[ DESTRUCTOR ]" << "\033[0m" << std::endl;
	delete cat;
	delete dog;

	return (0);
}
