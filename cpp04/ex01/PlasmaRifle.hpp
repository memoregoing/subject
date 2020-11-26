//
// Created by namhyung kim on 2020/11/25.
//

#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

# include "AWeapon.hpp"

class PlasmaRifle: public AWeapon
{
public:
	PlasmaRifle();
	PlasmaRifle(PlasmaRifle const &other);
	virtual ~PlasmaRifle();

	PlasmaRifle &operator=(PlasmaRifle const &other);

	void attack(void) const;
};

#endif
