/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:26:11 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/25 22:45:07 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <map>
#include <cfloat>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _database;


		std::string _trimWhiteSpaces(std::string &str);
		bool _isValidDateFormat(const std::string &str);
		bool _isValidValueFormat(const std::string &str);

		void _parseDatabase(void);
		std::string _parseDate(std::string &str);
		float _parseValue(std::string &str);

	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &rhs);
		BitcoinExchange &operator=(const BitcoinExchange &rhs);
		~BitcoinExchange(void);

		void execute(std::string input);
		void printDatabase(void) const;
};

#endif
