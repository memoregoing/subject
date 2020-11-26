//
// Created by namhyung kim on 2020/11/25.
//

#ifndef ISQUAD_HPP
# define ISQUAD_HPP

# include "ISpaceMarine.hpp"

class ISquad
{
public:
	virtual ~ISquad() {};
	virtual int getCount(void) const = 0;
	virtual ISpaceMarine *getUnit(int index) const = 0;
	virtual int push(ISpaceMarine *unit) = 0;
};

#endif
