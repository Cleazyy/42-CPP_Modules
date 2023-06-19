/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:20:56 by fluchten          #+#    #+#             */
/*   Updated: 2023/06/19 10:05:59 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	protected:
		std::string	_ideas[100];

	public:
		Brain(void);
		Brain(const Brain &rhs);
		Brain &operator=(const Brain &rhs);
		~Brain(void);
};

#endif
