/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:26:11 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/26 18:33:54 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>

class RPN
{
	private:

	public:
		RPN(void);
		RPN(const RPN &rhs);
		RPN &operator=(const RPN &rhs);
		~RPN(void);
};

#endif
