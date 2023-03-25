/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:38:12 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/25 11:23:19 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string	read_inputFile(std::string file)
{
	std::ifstream inputFile(file);
	if (!inputFile.is_open())
	{
		std::cerr << "Failed to open '" << file << "'" << std::endl;
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

std::string	replace_fileContent(std::string content, std::string s1, std::string s2)
{
	std::string	newFileContent = content;
	size_t pos = 0;
	while ((pos = newFileContent.find(s1, pos)) != std::string::npos)
	{
		newFileContent = newFileContent.substr(0, pos) + s2 + newFileContent.substr(pos + s1.length());
		pos += s2.length();
	}
	return (newFileContent);
}

int	create_outputFile(std::string file, std::string content)
{
	std::ofstream outputFile(file + ".replace");
	if (!outputFile.is_open())
	{
		std::cerr << "Failed to create '" << file << "'" << std::endl;
		return (1);
	}
	outputFile << content;
	outputFile.close();
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Error: wrong number of args." << std::endl;
		return (1);
	}
	std::string	file = av[1];
	std::string	s1 = av[2];
	std::string	s2 = av[3];

	std::string	fileContent = read_inputFile(file);
	if (fileContent.empty())
		return (1);
	std::string newFileContent = replace_fileContent(fileContent, s1, s2);
	if (create_outputFile(file, newFileContent) != 0)
		return (1);
	return (0);
}