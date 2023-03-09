/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:14:38 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/09 22:30:44 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iomanip>

# define MSG_CONTACT "\033[1;32m  ADD: \033[0m"
# define MSG_SEPARTOR "|----------|----------|----------|----------|"

class Contact
{
	private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickName;
	std::string _phoneNumber;
	std::string _darkestSecret;

	public :
	Contact(void);
	~Contact(void);

	void	getSettings(void);
	void	printHeaderPhoneBook();
	void	printPhoneBook(int index);
};

#endif