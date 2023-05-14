/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 10:50:14 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/14 13:42:49 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	std::srand(std::time(NULL));
	int random = std::rand() % 3;

	switch (random)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
		default:
			return (NULL);
	}
}

void	identify(Base *p)
{
	A *a = dynamic_cast<A *>(p);
	if (a != NULL)
		std::cout << "Base: A" << std::endl;

	B *b = dynamic_cast<B *>(p);
	if (b != NULL)
		std::cout << "Base: B" << std::endl;

	C *c = dynamic_cast<C *>(p);
	if (c != NULL)
		std::cout << "Base: C" << std::endl;
}

void	identify(Base &p)
{
	try {
		A &a = dynamic_cast<A &>(p);
		(void) a;
		std::cout << "Base: A" << std::endl;
	}	
	catch (std::bad_cast &bc) {}

	try {
		B &b = dynamic_cast<B &>(p);
		(void) b;
		std::cout << "Base: B" << std::endl;
	}	
	catch (std::bad_cast &bc) {}

	try {
		C &c = dynamic_cast<C &>(p);
		(void) c;
		std::cout << "Base: C" << std::endl;
	}	
	catch (std::bad_cast &bc) {}
}

int	main(void)
{
	std::cout << "[ BASE A ]" << std::endl;
	Base *a = new A();
	identify(a);
	identify(*a);
	delete a;
	std::cout << std::endl;

	std::cout << "[ BASE B ]" << std::endl;
	Base *b = new B();
	identify(b);
	identify(*b);
	delete b;
	std::cout << std::endl;

	std::cout << "[ BASE C ]" << std::endl;
	Base *c = new C();
	identify(c);
	identify(*c);
	delete c;
	std::cout << std::endl;

	std::cout << "[ BASE RANDOM ]" << std::endl;
	Base *random = generate();
	identify(random);
	identify(*random);
	delete random;

	return (0);
}
