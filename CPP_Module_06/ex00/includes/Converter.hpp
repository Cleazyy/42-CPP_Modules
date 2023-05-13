/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:01:26 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/13 20:49:20 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>

enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	SPECIAL,
	INVALID
};

class Converter
{
	private:
		const std::string	_nb;
		e_type				_type;

		int		_strToInt(std::string str, int *overflow);

		bool	_isChar(void);
		bool	_isInt(void);
		bool	_isFloat(void);
		bool	_isDouble(void);
		bool	_isSpecial(void);

		void	_convertChar(void);
		void	_convertInt(void);
		void	_convertFloat(void);
		void	_convertDouble(void);

		void	_displayChar(char c);
		void	_displayInt(int nb);
		void	_displayFloat(float nb);
		void	_displayDouble(double nb);
		void	_displaySpecial(void);

	public:
		Converter(void);
		Converter(const std::string nb);
		Converter(const Converter& rhs);
		Converter& operator=(const Converter& rhs);
		~Converter(void);

		void	execute(void);
};

#endif
