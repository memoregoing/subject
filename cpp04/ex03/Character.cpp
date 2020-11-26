//
// Created by namhyung kim on 2020/11/25.
//

#include "Character.hpp"

Character::Character(std::string const &name):name(name), equipped(0)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = nullptr;
}

Character::Character(Character const &other):name(other.name), equipped(0)
{
	for (int i = 0; i < other.equipped; i++)
		this->equip(other.inventory[i]->clone());
	for (int i = this->equipped; i < 4; i++)
		this->inventory[i] = nullptr;
}

Character::~Character()
{
	for (int i = 0; i < this->equipped; i++)
		delete this->inventory[i];
}

Character &Character::operator=(Character const &other)
{
	this->name = other.name;
	for (int i = 0; i < this->equipped; i++)
		delete this->inventory[i];
	this->equipped = 0;
	for (int i = 0; i < other.equipped; i++)
		this->equip(other.inventory[i]->clone());
	for (int i = this->equipped; i < 4; i++)
		this->inventory[i] = nullptr;
	return (*this);
}

std::string const &Character::getName(void) const
{
	return (this->name);
}

void Character::equip(AMateria *m)
{
	if (this->equipped == 4 || m == nullptr)
		return ;
	for (int i = 0; i < this->equipped; i++)
		if (this->inventory[i] == m)
			return ;
	this->inventory[this->equipped++] = m;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= this->equipped || this->inventory[idx] == nullptr)
		return ;
	for (int i = idx; i < 3; i++)
	{
		this->inventory[i] = this->inventory[i + 1];
		this->inventory[i + 1] = nullptr;
	}
	this->equipped--;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= this->equipped || this->inventory[idx] == nullptr)
		return ;
	this->inventory[idx]->use(target);
}
