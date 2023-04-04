/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:20:56 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/03 17:23:51 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H

# include <iostream>

class Brain
{
	protected:
		std::string	_ideas[100];

	public:
		Brain(void);
		Brain(const Brain& rhs);
		Brain& operator=(const Brain& rhs);
		~Brain(void);
};

#endif
