/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:01:26 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/13 16:25:09 by fluchten         ###   ########.fr       */
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
	INVALID
};

class Converter
{
	private:
		const std::string	_nb;
		e_type				_type;

		bool	_isChar(void);
		bool	_isInt(void);
		bool	_isFloat(void);
		bool	_isDouble(void);

		void	_convertChar(void);
		void	_convertInt(void);
		void	_convertFloat(void);
		void	_convertDouble(void);

		void	_displayChar(char resChar);
		void	_displayInt(int resInt);
		void	_displayFloat(float resFloat);
		void	_displayDouble(double resDouble);
		void	_display(char resChar, int resInt, float resFloat, double resDouble);

	public:
		Converter(void);
		Converter(const std::string nb);
		Converter(const Converter& rhs);
		Converter& operator=(const Converter& rhs);
		~Converter(void);

		void	execute(void);

		class InvalidTypeException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		class OverflowException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& o, const Converter& rhs);

#endif
