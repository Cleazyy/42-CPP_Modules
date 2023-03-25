/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 12:03:36 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/25 12:34:55 by fluchten         ###   ########.fr       */
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

std::string	File::read_inputFile(void)
{
	std::ifstream inputFile(this->_inFile);
	if (!inputFile.is_open())
	{
		std::cerr << "Failed to open '" << this->_inFile << "'" << std::endl;
		return ("");
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
	return (content);
}

std::string	File::replace_fileContent(std::string content, std::string s1, std::string s2)
{
	std::string	newContent = content;
	size_t pos = 0;
	while ((pos = newContent.find(s1, pos)) != std::string::npos)
	{
		newContent = newContent.substr(0, pos) + s2 + newContent.substr(pos + s1.length());
		pos += s2.length();
	}
	return (newContent);
}

int	File::create_outputFile(std::string content)
{
	std::ofstream outputFile(this->_outFile);
	if (!outputFile.is_open())
	{
		std::cerr << "Failed to create '" << this->_outFile << "'" << std::endl;
		return (1);
	}
	outputFile << content;
	outputFile.close();
	return (0);
}