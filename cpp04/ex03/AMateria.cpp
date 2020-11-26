//
// Created by namhyung kim on 2020/11/25.
//

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type):
	_type(type), _xp(0)
{
}

AMateria::~AMateria()
{
}

std::string const &AMateria::getType(void) const
{
	return (this->_type);
}

unsigned int AMateria::getXP(void) const
{
	return (this->_xp);
}

void AMateria::use(ICharacter &target)
{
	(void)target;
	this->_xp += 10;
}
