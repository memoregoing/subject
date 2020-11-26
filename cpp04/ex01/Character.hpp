//
// Created by namhyung kim on 2020/11/25.
//

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character
{
private:
	Character();

	std::string name;
	int ap;
	AWeapon *weapon;
public:
	Character(std::string const &name);
	Character(Character const &other);
	virtual ~Character();

	Character &operator=(Character const &other);

	std::string const &getName(void) const;
	int getAP(void) const;
	AWeapon *getWeapon(void) const;

	void recoverAP(void);
	void equip(AWeapon *weapon);
	void attack(Enemy *enemy);
};

std::ostream &operator<<(std::ostream &out, Character const &chara);

#endif
