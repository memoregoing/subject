//
// Created by namhyung kim on 2020/11/23.
//

#include "FragTrap.hpp"

// C11이상에서는 클레스내에서 배열 초기화를 할 수 있지만 여기선 안된다고 나오더군요.
// 그리고 스태틱 변수를 사용하면 객체마다 생성 되는게 아니라 클래스가 메모리에 적재 될 때 같이 올라가기 때문에
// 이 클래스의 모든 인스턴스가 스태틱 변수를 공유하게 됩니다.
std::string FragTrap::quotes[FragTrap::nbrQuotes] = {
        "Cpp 극혐",
        "빨리 하고싶다 언제 끝나나나나나",
        "포인트 이벤트 감사합니다",
        "가자아 가자아가자아 뚫자",
        "2달만에 서프젝트 하네요?"
};

FragTrap::FragTrap(std::string const &name):
        ClapTrap(name)
{
    std::cout << this->name << ": Recompiling my combat code !" << std::endl;
    this->meleeAttackDamage = 30;
    this->rangedAttackDamage = 20;
    this->armorDamageReduction = 5;
}

FragTrap::FragTrap(FragTrap const &other):
        ClapTrap(other.name)
{
    std::cout << "복사 생성자를 호출 그런데 부모의 생성자를 사용 왜냐하면 부모한테 인스턴스 변수 있으니까" << std::endl;
    ClapTrap::copy(other);
}

FragTrap::~FragTrap()
{
    std::cout << "fragtrap 소멸자 소환"  << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &other)
{
    ClapTrap::copy(other);
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

void FragTrap::vaulthunter_dot_exe(std::string const &target)
{
    if (this->energyPoints >= 25)
    {
        this->energyPoints -= 25;
        std::cout << this->name << ": "
                  << FragTrap::quotes[rand() % FragTrap::nbrQuotes] << std::endl
                  << this->name << " attacks "
                  << target << " for " << ((rand() % this->meleeAttackDamage) + 1)
                  << " points of damage!" << std::endl;
    }
    else
    {
        std::cout << "FR4G-TP " << this->name << " is out of energy!" << std::endl;
    }
}