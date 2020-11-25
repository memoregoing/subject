//
// Created by namhyung kim on 2020/11/23.
//

#include "FragTrap.hpp"

// C11이상에서는 클레스내에서 배열 초기화를 할 수 있지만 여기선 안된다고 나오더군요.
// 그리고 스태틱 변수를 사용하면 객체마다 생성 되는게 아니라 클래스가 메모리에 적재 될 때 같이 올라가기 때문에
// 이 클래스의 모든 인스턴스가 스태틱 변수를 공유하게 됩니다.
std::string FragTrap::quotes[FragTrap::nbrQuotes] = {
        "Take that!",
        "Get off my lawn!",
        "Coffee? Black... like my soul.",
        "I am Fire, I am Death!",
        "Lightening! Kukachow!"
};

//래퍼런스 변수로 받을 경우 함수 내부에서 초기화 할 수 없기 때문에 콜론 초기화를 사용해서 초기화 한다.
FragTrap::FragTrap(const std::string &name):name(name)
{
    std::cout << this->name << "객체 생성" << std::endl;
    this->level = 1;
    this->hitPoints = 100;
    this->maxHitPoints = 100;
    this->energyPoints = 100;
    this->maxEnergyPoints = 100;
    this->meleeAttackDamage = 30;
    this->rangedAttackDamage = 20;
    this->armorDamageReduction = 5;
}

FragTrap::FragTrap(const FragTrap &other):name(other.name)
{
    std::cout << this->name << "복사 생성자에 의한 객체 생성" << std::endl;
    this->level = other.level;
    this->hitPoints = other.hitPoints;
    this->maxHitPoints = other.maxHitPoints;
    this->energyPoints = other.energyPoints;
    this->maxEnergyPoints = other.maxEnergyPoints;
    this->meleeAttackDamage = other.meleeAttackDamage;
    this->rangedAttackDamage = other.rangedAttackDamage;
    this->armorDamageReduction = other.armorDamageReduction;
}

FragTrap::~FragTrap()
{
    std::cout << this->name << "소멸자 호출로 인한 객체 삭제"  << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &other)
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

void FragTrap::meleeAttack(std::string const &target)
{
    std::cout << this->name << " attacks "
              << target << " at melee, causing "
              << this->meleeAttackDamage << " points of damage!" << std::endl;
}

void FragTrap::rangedAttack(std::string const &target)
{
    std::cout << this->name << " attacks "
              << target << " at range, causing "
              << this->rangedAttackDamage << " points of damage!" << std::endl;
}

bool FragTrap::takeDamage(unsigned int amount)
{
    int dealt = amount - this->armorDamageReduction;
    this->hitPoints -= dealt;
    if (this->hitPoints < 0)
    {
        dealt += this->hitPoints;
        this->hitPoints = 0;
    }
    std::cout << this->name << " take "
              << dealt << " points of damage!" << std::endl;
    return (this->hitPoints == 0);
}

void FragTrap::beRepaired(unsigned int amount)
{
    int healed = amount;
    this->hitPoints += amount;
    if (this->hitPoints > this->maxHitPoints)
    {
        healed -= (this->hitPoints - this->maxHitPoints);
        this->hitPoints = this->maxHitPoints;
    }
    std::cout << this->name << " is repaired for "
              << healed << "!" << std::endl;
}

void FragTrap::vaulthunter_dot_exe(std::string const &target)
{
    if (this->energyPoints >= 25)
    {
        this->energyPoints -= 25;
        // 난수 생성을 통한 스테틱 배열에서 뽑아온다.
        // static을 사용하는 경우는 클레스의 객체에 직접적인 영향을 끼치지 않는 경우, 관계는 있으나 직접적이지 않는 경우 사용한다.
        std::cout << this->name << ": "
                  << FragTrap::quotes[rand() % FragTrap::nbrQuotes] << std::endl
                  << this->name << " attacks "
                  << target << " for " << ((rand() % this->meleeAttackDamage) + 1)
                  << " points of damage!" << std::endl;
    }
    else
    {
        std::cout << "FR4G-TP " << this->name << "is out of energy!" << std::endl;
    }
}