/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:26:11 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/23 18:14:41 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <iterator>
# include <vector>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void) : std::stack<T>() {}
		MutantStack(const MutantStack &rhs) : std::stack<T>(rhs) {}
		MutantStack &operator=(const MutantStack &rhs) {(void) rhs; return (*this);}
		~MutantStack(void) {}

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin(void) {return (this->c.begin());}
		iterator end(void) {return (this->c.end());}

		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		const_iterator begin(void) const {return (this->c.begin());}
		const_iterator end(void) const {return (this->c.end());}

		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator rbegin(void) {return (this->c.rbegin());}
		reverse_iterator rend(void) {return (this->c.rend()); }

		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator rbegin(void) const {return (this->c.rbegin());}
		const_reverse_iterator rend(void) const {return (this->c.rend());}
};

#endif
