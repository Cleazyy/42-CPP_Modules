/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:52:38 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/04 22:16:25 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria*	_inventory[4];

	public:
		Character(void);
		Character(const std::string& name);
		Character(const Character& rhs);
		Character& operator=(const Character& rhs);
		~Character(void);

		const std::string& 	getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
};

#endif
