//
// Created by namhyung kim on 2020/11/25.
//

#ifndef POWERFIST_HPP
# define POWERFIST_HPP

# include "AWeapon.hpp"

class PowerFist: public AWeapon
{
public:
	PowerFist();
	PowerFist(PowerFist const &other);
	virtual ~PowerFist();

	PowerFist &operator=(PowerFist const &other);

	void attack(void) const;
};

#endif
