//
// Created by namhyung kim on 2020/11/25.
//

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <iostream>
# include <string>

class AWeapon
{
protected:
	AWeapon();

	std::string name;
	int apCost;
	int damage;
public:
	AWeapon(std::string const &name, int apcost, int damage);
	AWeapon(AWeapon const &other);
	virtual ~AWeapon();

	AWeapon &operator=(AWeapon const &other);

	std::string const &getName(void) const;
	int getAPCost(void) const;
	int getDamage(void) const;

	virtual void attack() const = 0;
};

#endif
