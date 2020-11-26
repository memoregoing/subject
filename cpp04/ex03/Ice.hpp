//
// Created by namhyung kim on 2020/11/25.
//

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice: public AMateria
{
private:
public:
	Ice();
	Ice(Ice const &other);
	virtual ~Ice();

	Ice &operator=(Ice const &other);

	AMateria *clone(void) const;
	void use(ICharacter &target);
};

#endif
