/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:50:13 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/24 09:07:10 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

class Weapon
{
	private:
		std::string	_type;

	public:
		Weapon(void);
		~Weapon(void);

		std::string&	getType(void);
		void			setType(std::string newType);	
};