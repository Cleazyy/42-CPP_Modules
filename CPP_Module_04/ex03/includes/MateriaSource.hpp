/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:46:56 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/04 20:10:52 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria*	_materias[4];

	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource& rhs);
		MateriaSource& operator=(const MateriaSource& rhs);
		~MateriaSource(void);

		void		learnMateria(AMateria*);
		AMateria*	createMateria(const std::string& type);
};

#endif
