//
// Created by namhyung kim on 2020/11/24.
//

#include "ScavTrap.hpp"

std::string ScavTrap::challenges[ScavTrap::nbrChalls] = {
        "CPP 언제하지?",
        "static배열에서 왔지",
        "배고프다",
        "CPP극혐입니다",
        "포인트 이벤트 감사합니다."
};

ScavTrap::ScavTrap(std::string const &name):ClapTrap(name)
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

ScavTrap::ScavTrap(ScavTrap const &other):ClapTrap(other.name)
{
    std::cout << "복사 생성자 소환 소환" << std::endl;
    ClapTrap::copy(other);
}

ScavTrap::~ScavTrap()
{
    std::cout << this->name << "소멸자를 소환한다."  << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other)
{
    ClapTrap::copy(other);
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

void ScavTrap::challengeNewcomer(void)
{
    std::cout << this->name << ": ";
    std::cout << ScavTrap::challenges[rand() % ScavTrap::nbrChalls] << std::endl;
}