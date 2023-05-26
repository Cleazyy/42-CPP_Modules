/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:26:11 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/26 14:14:14 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _database;

		std::string	_trimWhiteSpaces(std::string &str);
		bool _isValidDateFormat(std::string &str);
		bool _isValidValueFormat(std::string &str);

		float _getValue(std::string &str);
		std::string _parseDate(std::string &str);
		float _parseValue(std::string &str);
		void _parseDatabase(void);

	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &rhs);
		BitcoinExchange &operator=(const BitcoinExchange &rhs);
		~BitcoinExchange(void);

		void executeFile(std::string input);
};

#endif
