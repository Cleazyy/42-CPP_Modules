/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:01:26 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/14 09:31:38 by fluchten         ###   ########.fr       */
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
		static int		strToInt(std::string str, int *overflow);
		static e_type	getType(std::string str);

		static bool		isChar(std::string str);
		static bool		isInt(std::string str);
		static bool		isFloat(std::string str);
		static bool		isDouble(std::string str);
		static bool		isSpecial(std::string str);

		static void		convertChar(std::string str);
		static void		convertInt(std::string str);
		static void		convertFloat(std::string str);
		static void		convertDouble(std::string str);

		static void		displayChar(char c);
		static void		displayInt(int nb);
		static void		displayFloat(float nb);
		static void		displayDouble(double nb);
		static void		displaySpecial(std::string str);

		Converter(void);
		Converter(const std::string nb);
		Converter(const Converter &rhs);
		Converter &operator=(const Converter &rhs);
		~Converter(void);

	public:
		static void	execute(std::string str);
};

#endif
