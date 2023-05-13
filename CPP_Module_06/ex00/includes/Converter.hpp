/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:01:26 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/13 11:30:35 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>

class Converter
{
	private:
		const std::string	_nb;
		std::string			_type;

		bool	_isChar(void);
		bool	_isInt(void);
		bool	_isFloat(void);
		bool	_isDouble(void);

		void	_convertChar(void);
		void	_display(char resChar);

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
