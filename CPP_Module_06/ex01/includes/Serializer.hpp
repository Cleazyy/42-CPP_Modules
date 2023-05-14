/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 10:50:26 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/14 11:17:52 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include "Data.hpp"

class Serializer
{
	private:
		Serializer(void);
		Serializer(const Serializer &rhs);
		Serializer &operator=(const Serializer &rhs);
		~Serializer(void);

	public:
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};

#endif
