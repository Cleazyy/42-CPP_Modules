/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:01:26 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/10 18:45:32 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>

class Converter
{
	private:
		const std::string	_nb;

		bool	_isChar(void);
		void	_displayChar(void);

	public:
		Converter(void);
		Converter(const std::string nb);
		Converter(const Converter& rhs);
		Converter& operator=(const Converter& rhs);
		~Converter(void);

		void	execute(void);
};

std::ostream&	operator<<(std::ostream& o, const Converter& rhs);

#endif
