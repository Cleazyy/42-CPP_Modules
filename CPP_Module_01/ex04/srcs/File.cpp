/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 12:03:36 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/25 16:57:24 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.hpp"

File::File(std::string file) : _inFile(file), _outFile(file + ".replace")
{
	return ;
}

File::~File(void)
{
	return ;
}

int	File::read(void)
{
	std::ifstream inputFile(this->_inFile);
	if (!inputFile.is_open())
	{
		std::cout << "Failed to open '" << this->_inFile << "'" << std::endl;
		return (1);
	}
	std::string	line;
	std::string	content;
	while (std::getline(inputFile, line))
	{
		content += line;
		if (!inputFile.eof()) 
			content += "\n";
	}
	inputFile.close();
	this->_fileContent = content;
	return (0);
}

void	File::replace(std::string s1, std::string s2)
{
	std::string	temp = this->_fileContent;
	size_t pos = 0;
	while ((pos = temp.find(s1, pos)) != std::string::npos)
	{
		temp = temp.substr(0, pos) + s2 + temp.substr(pos + s1.length());
		pos += s2.length();
	}
	this->_fileContent = temp;
}

int	File::create(void)
{
	std::ofstream outputFile(this->_outFile);
	if (!outputFile.is_open())
	{
		std::cout << "Failed to create '" << this->_outFile << "'" << std::endl;
		return (1);
	}
	outputFile << this->_fileContent;
	outputFile.close();
	return (0);
}