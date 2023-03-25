/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 12:01:33 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/25 12:49:18 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

# include <iostream>
# include <fstream>

class File
{
	private:
		std::string	_inFile;
		std::string	_outFile;
		std::string	_fileContent;

	public:
		File(std::string file);
		~File(void);

		int		read(void);
		void	replace(std::string s1, std::string s2);
		int		create(void);
};

#endif