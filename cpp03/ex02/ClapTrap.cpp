//
// Created by namhyung kim on 2020/11/24.
//

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string const &name):name(name)
{
    std::cout << "이름을 래퍼런스 변수로 받는 생성자 소환" << std::endl;
    this->level = 1;
    this->hitPoints = 100;
    this->maxHitPoints = 100;
    this->energyPoints = 100;
    this->maxEnergyPoints = 100;
    this->meleeAttackDamage = 100;
    this->rangedAttackDamage = 100;
    this->armorDamageReduction = 100;
}

ClapTrap::ClapTrap(ClapTrap const &other):name(other.name)
{
    std::cout << "ClapTrap의 복사 생성자 소환" << std::endl;
    ClapTrap::copy(other);
}

ClapTrap::~ClapTrap()
{
    std::cout << "claptrap의 소멸자 소환" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other)
{
    ClapTrap::copy(other);
    return (*this);
}

void ClapTrap::copy(ClapTrap const &other)
{
    this->level = other.level;
    this->hitPoints = other.hitPoints;
    this->maxHitPoints = other.maxHitPoints;
    this->energyPoints = other.energyPoints;
    this->maxEnergyPoints = other.maxEnergyPoints;
    this->meleeAttackDamage = other.meleeAttackDamage;
    this->rangedAttackDamage = other.rangedAttackDamage;
    this->armorDamageReduction = other.armorDamageReduction;
}

void ClapTrap::meleeAttack(std::string const &target)
{
    std::cout << "내가 " << this->name << " 공격을 "
              << target << " 밀리어택으로 "
              << this->meleeAttackDamage << " 이만큼이나? " << std::endl;
}

void ClapTrap::rangedAttack(std::string const &target)
{
    std::cout << "내가 " << this->name << " 공격을 "
              << target << " 스플래쉬로 !!"
              << this->rangedAttackDamage << std::endl;
}

bool ClapTrap::takeDamage(unsigned int amount)
{
    int dealt = amount - this->armorDamageReduction;
    this->hitPoints -= dealt;
    if (this->hitPoints < 0)
    {
        dealt += this->hitPoints;
        this->hitPoints = 0;
    }
    std::cout << this->name << " 아프다 " << dealt << " 이만큼이나 " << std::endl;
    return (this->hitPoints == 0);
}

void ClapTrap::beRepaired(unsigned int amount)
{
    int healed = amount;
    this->hitPoints += amount;
    if (this->hitPoints > this->maxHitPoints)
    {
        healed -= (this->hitPoints - this->maxHitPoints);
        this->hitPoints = this->maxHitPoints;
    }
    std::cout << this->name << " 피가 찬다 더라" << healed << "호" << std::endl;
}