/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:26:11 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/22 20:51:31 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>

class Span
{
	private:
		unsigned int _N;
		std::vector<int> _numbers;

	public:
		Span(void);
		Span(unsigned int N);
		Span(const Span &rhs);
		Span &operator=(const Span &rhs);
		~Span(void);

		const std::vector<int> &getNumbers() const;

		void addNumber(int N);
		void addNumbers(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);
		unsigned int shortestSpan(void) const;
		unsigned int longestSpan(void) const;
};

std::ostream &operator<<(std::ostream &o, const Span &rhs);

#endif
