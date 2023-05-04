/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 11:49:52 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/04 19:38:24 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					_fixed;
		static const int	_bits = 8;

	public:
		Fixed(void);
		Fixed(const Fixed& rhs);
		Fixed& operator=(const Fixed& rhs);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif