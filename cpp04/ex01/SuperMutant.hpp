//
// Created by namhyung kim on 2020/11/25.
//

#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

# include "Enemy.hpp"

class SuperMutant: public Enemy
{
public:
	SuperMutant();
	SuperMutant(SuperMutant const &other);
	virtual ~SuperMutant();

	SuperMutant &operator=(SuperMutant const &other);

	void takeDamage(int damage);
};

#endif
