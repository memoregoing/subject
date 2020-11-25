//
// Created by namhyung kim on 2020/11/24.
//

#include "ScavTrap.hpp"

#include "ScavTrap.hpp"

std::string ScavTrap::challenges[ScavTrap::nbrChalls] = {
        "CPP 언제하지?",
        "static배열에서 왔지",
        "배고프다",
        "CPP극혐입니다",
        "포인트 이벤트 감사합니다."
};

ScavTrap::ScavTrap(std::string const &name):name(name)
{
    std::cout << this->name << "레퍼런스변수를 받는 생성자 소환" << std::endl;
    this->level = 1;
    this->hitPoints = 100;
    this->maxHitPoints = 100;
    this->energyPoints = 50;
    this->maxEnergyPoints = 50;
    this->meleeAttackDamage = 20;
    this->rangedAttackDamage = 15;
    this->armorDamageReduction = 3;
}

ScavTrap::ScavTrap(ScavTrap const &other):name(other.name)
{
    std::cout << this->name << "복사 생성자를 소환한다" << std::endl;
    this->level = other.level;
    this->hitPoints = other.hitPoints;
    this->maxHitPoints = other.maxHitPoints;
    this->energyPoints = other.energyPoints;
    this->maxEnergyPoints = other.maxEnergyPoints;
    this->meleeAttackDamage = other.meleeAttackDamage;
    this->rangedAttackDamage = other.rangedAttackDamage;
    this->armorDamageReduction = other.armorDamageReduction;
}

ScavTrap::~ScavTrap()
{
    std::cout << this->name << "소멸자를 소환한다."  << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other)
{
    this->name = other.name;
    this->level = other.level;
    this->hitPoints = other.hitPoints;
    this->maxHitPoints = other.maxHitPoints;
    this->energyPoints = other.energyPoints;
    this->maxEnergyPoints = other.maxEnergyPoints;
    this->meleeAttackDamage = other.meleeAttackDamage;
    this->rangedAttackDamage = other.rangedAttackDamage;
    this->armorDamageReduction = other.armorDamageReduction;
    return (*this);
}

void ScavTrap::meleeAttack(std::string const &target)
{
    std::cout << this->name << " 가  "
              << target << " 데미지를 주는데 "
              << this->meleeAttackDamage << " 받았습니다." << std::endl;
}

void ScavTrap::rangedAttack(std::string const &target)
{
    std::cout << this->name << " 스플래쉬 데미지를 "
              << target << " 주는데 "
              << this->rangedAttackDamage << " 받았습니다." << std::endl;
}

bool ScavTrap::takeDamage(unsigned int amount)
{
    int dealt = amount - this->armorDamageReduction;
    this->hitPoints -= dealt;
    if (this->hitPoints < 0)
    {
        dealt += this->hitPoints;
        this->hitPoints = 0;
    }
    std::cout << this->name << " 데미지 " << dealt << " 받아부렸" << std::endl;
    return (this->hitPoints == 0);
}

void ScavTrap::beRepaired(unsigned int amount)
{
    int healed = amount;
    this->hitPoints += amount;
    if (this->hitPoints > this->maxHitPoints)
    {
        healed -= (this->hitPoints - this->maxHitPoints);
        this->hitPoints = this->maxHitPoints;
    }
    std::cout << this->name << " 가 피가  " << healed << " 차더" << std::endl;
}

void ScavTrap::challengeNewcomer(void)
{
    std::cout << this->name << ": ";
    std::cout << ScavTrap::challenges[rand() % ScavTrap::nbrChalls] << std::endl;
}