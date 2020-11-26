//
// Created by namhyung kim on 2020/11/25.
//

#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP

# include "ISpaceMarine.hpp"

class TacticalMarine: public ISpaceMarine
{
public:
	TacticalMarine();
	TacticalMarine(TacticalMarine const &other);
	virtual ~TacticalMarine();

	TacticalMarine &operator=(TacticalMarine const &other);

	ISpaceMarine *clone(void) const;
	void battleCry(void) const;
	void rangedAttack(void) const;
	void meleeAttack(void) const;
};

#endif
