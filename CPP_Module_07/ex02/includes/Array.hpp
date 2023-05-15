/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:01:26 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/15 17:45:59 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP 

template<typename T>
class Array
{
	private:
		T *_array;
		unsigned int _size;

	public:
		Array(void) : _array(nullptr), _size(0) {}

		Array(unsigned int size) : _array(new T[size]), _size(size) {}

		Array(const Array &rhs) : _array(new T[rhs._size]), _size(rhs._size)
		{
			for (unsigned int i = 0; i < this->_size; i++) {
				this->_array[i] = rhs._array[i];
			}
		}

		Array &operator=(const Array &rhs)
		{
			if (this != &rhs)
			{
				delete [] this->_array;
				this->_size = rhs._size;
				this->_array = new T[this->_size];
				for (unsigned int i = 0; i < this->_size; i++) {
					this->_array[i] = rhs._array[i];
				}
			}
			return (*this);
		}

		~Array(void)
		{
			delete [] this->_array;
		}
};

#endif
