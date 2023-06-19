/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:50:45 by fluchten          #+#    #+#             */
/*   Updated: 2023/06/19 10:27:11 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Character.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main(void)
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter*	me = new Character("me");
	ICharacter*	bob = new Character("bob");
	AMateria*	tmp;

	std::cout << "\033[1;32m" << "[ INVENTORY [2] ]" << "\033[0m" << std::endl;

    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    me->use(0, *bob);
    me->use(1, *bob);
	me->use(2, *bob);
	std::cout << std::endl;

	std::cout << "\033[1;32m" << "[ INVENTORY [4] ]" << "\033[0m" << std::endl;
	
	tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);

	me->use(0, *bob);
    me->use(1, *bob);
	me->use(2, *bob);
    me->use(3, *bob);
	std::cout << std::endl;

	std::cout << "\033[1;31m" << "[ FULL INVENTORY ]" << "\033[0m" << std::endl;

	tmp = src->createMateria("cure");
    me->equip(tmp);
	std::cout << std::endl;

	std::cout << "\033[1;33m" << "[ UNEQUIP INVENTORY ]" << "\033[0m" << std::endl;

	me->unequip(6);
	std::cout << std::endl;

	me->unequip(1);
	me->unequip(2);
	me->use(0, *bob);
    me->use(1, *bob);
	me->use(2, *bob);
    me->use(3, *bob);

    delete bob;
    delete me;
    delete src;

    return (0);
}
