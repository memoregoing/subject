//
// Created by namhyung kim on 2020/11/24.
//

#ifndef CPP_CLAPTRAP_HPP
#define CPP_CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap {
    // 두 클레스가 공통으로 사용하는 인스턴스의 변수들을 부모 클레스로 이동 시킨다.
    // protected 키워드는 상속 관계 일 대 접근 가능한 키워드로 정보 은닉을 위해 활용 된다.
protected:
    ClapTrap();
    std::string     name;
    int             level;
    int             hitPoints;
    int             maxHitPoints;
    int             energyPoints;
    int             maxEnergyPoints;
    int             meleeAttackDamage;
    int             rangedAttackDamage;
    int             armorDamageReduction;

    void copy(ClapTrap const &other);
public:
    ClapTrap(std::string const &name);
    ClapTrap(ClapTrap const &other);
    virtual ~ClapTrap(); // 드디어 이 virtual 소멸자를 확인 할 수 있는 exam에 도착 하였습니다!!

    ClapTrap &operator=(ClapTrap const &other);

    virtual void meleeAttack(std::string const &target);
    virtual void rangedAttack(std::string const &target);
    bool takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};


#endif //CPP_CLAPTRAP_HPP
