/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:26:11 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/27 22:22:48 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <sstream>
# include <vector>
# include <deque>
# include <ctime>

class PmergeMe
{
	private:
		std::vector<int> _vector;
		std::deque<int> _deque;

		bool _isInt(char *str);
		void _parseInput(int ac, char **av);
		void _mergeVector(int left, int middle, int right);
		void _mergeSortVector(int left, int right);

	public:
		PmergeMe(void);
		PmergeMe(int ac, char **av);
		PmergeMe(const PmergeMe &rhs);
		PmergeMe &operator=(const PmergeMe &rhs);
		~PmergeMe(void);

		void sortVector(void);
		void sortDeque(void);
};

#endif
