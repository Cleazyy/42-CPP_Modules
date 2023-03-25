/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:38:12 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/25 10:55:07 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

static int	read_and_replace(std::string file, std::string s1, std::string s2)
{
	std::string	content;
	std::string	line;

	std::ifstream inputFile(file);
	if (!inputFile.is_open())
	{
		std::cerr << "Failed to open '" << file << "'" << std::endl;
		return (1);
	}
	while (std::getline(inputFile, line))
	{
		content += line;
		if (!inputFile.eof()) 
			content += "\n";
	}
	inputFile.close();

	size_t pos = 0;
	while ((pos = content.find(s1, pos)) != std::string::npos)
	{
		content = content.substr(0, pos) + s2 + content.substr(pos + s1.length());
		pos += s2.length();
	}

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
	if (read_and_replace(file, s1, s2) != 0)
		return (1);
	return (0);
}