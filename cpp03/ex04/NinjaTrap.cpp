//
// Created by namhyung kim on 2020/11/25.
//

#include "NinjaTrap.hpp"

//부모를 상속 받아서 부모생성자에서 초기
NinjaTrap::NinjaTrap(std::string const &name):ClapTrap(name)
{
    std::cout << this->name << "일반 생성자 호출" << std::endl;
    this->hitPoints = 60;
    this->maxHitPoints = 60;
    this->energyPoints = 120;
    this->maxEnergyPoints = 120;
    this->meleeAttackDamage = 60;
    this->rangedAttackDamage = 5;
    this->armorDamageReduction = 0;
}

NinjaTrap::NinjaTrap(NinjaTrap const &other):ClapTrap(other.name)
{
    std::cout << this->name << "복사 생성자 호출" << std::endl;
    ClapTrap::copy(other);
}

NinjaTrap::~NinjaTrap()
{
    std::cout << this->name << "소멸자 호출"  << std::endl;
}

NinjaTrap &NinjaTrap::operator=(NinjaTrap const &other)
{
    ClapTrap::copy(other);
    return (*this);
}

void NinjaTrap::meleeAttack(std::string const &target)
{
    std::cout << this->name << " swing is Katana and deals "
              << this->meleeAttackDamage << " points of damage to "
              << target << "!" << std::endl;
}

void NinjaTrap::rangedAttack(std::string const &target)
{
    std::cout << this->name << " throw a Shuriken at "
              << target << " and deals " << this->meleeAttackDamage
              << " points of damage!" << std::endl;
}

void NinjaTrap::ninjaShoebox(FragTrap &trap)
{
    std::cout << this->name << " tries to tickle " << trap.getName()
              << " but realize he has no feets." << std::endl;
}

void NinjaTrap::ninjaShoebox(ScavTrap &trap)
{
    if (this->energyPoints >= 20)
    {
        this->energyPoints -= 20;
        std::cout << this->name << " try to cut trough " << trap.getName()
                  << " and damage him for " << this->rangedAttackDamage << "!" << std::endl;
        trap.takeDamage(this->rangedAttackDamage);
    }
    else
        std::cout << this->name << " is too tired." << std::endl;
}

void NinjaTrap::ninjaShoebox(ClapTrap &trap)
{
    if (this->energyPoints >= 60)
    {
        this->energyPoints -= 60;
        std::cout << this->name << " sense the ClapTrap " << trap.getName()
                  << " but can't see it." << std::endl;
    }
    else
    {
        std::cout << this->name << " finally see the ClapTrap " << trap.getName()
                  << " before falling on the ground." << std::endl;
        this->takeDamage(this->hitPoints + this->armorDamageReduction);
    }
}

void NinjaTrap::ninjaShoebox(NinjaTrap &trap)
{
    if ((rand() % 100) > 50)
    {
        std::cout << this->name << " throw Shuriken at " << trap.getName()
                  << " and damage him for " << this->rangedAttackDamage << "!" << std::endl;
    }
    else
    {
        std::cout << this->name << " throw Shuriken at " << trap.getName()
                  << " but misses" << std::endl;
    }
}