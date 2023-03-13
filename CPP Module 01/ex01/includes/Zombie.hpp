/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:05:17 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/13 20:13:48 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>

class Zombie
{
	private:
	std::string	_name;

	public:
	Zombie(void);
	~Zombie(void);

	void	announce(void);
	void	setName(std::string name);
};

Zombie*	zombieHorde(int N, std::string name);

#endif