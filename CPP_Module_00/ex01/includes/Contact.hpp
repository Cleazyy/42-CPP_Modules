/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:14:38 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/29 08:57:10 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact
{
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string _darkestSecret;

		void _init(void);
		bool _isPhoneNumber(const std::string &str);
		bool _isExist(void);
		std::string _resizeString(const std::string &str);

	public :
		Contact(void);
		~Contact(void);

		void getSettings(void);
		void printElementList(int index);
		void printContact(int index);

};

#endif
