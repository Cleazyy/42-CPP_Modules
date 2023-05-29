/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:05:17 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/29 09:05:13 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

# define NB_ZOMBIES 5

class Zombie
{
	private:
		std::string _name;

	public:
		Zombie(void);
		~Zombie(void);

		void announce(void);
		void setName(std::string name);
};

Zombie *zombieHorde(int N, std::string name);

#endif
