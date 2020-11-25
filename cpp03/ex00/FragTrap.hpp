//
// Created by namhyung kim on 2020/11/23.
//

#ifndef CPP_FRAGTRAP_HPP
#define CPP_FRAGTRAP_HPP

# include <iostream>
# include <string>

class FragTrap {
private:
    FragTrap();

    std::string     name;
    int             level;
    int             hitPoints;
    int             maxHitPoints;
    int             energyPoints;
    int             maxEnergyPoints;
    int             meleeAttackDamage;
    int             rangedAttackDamage;
    int             armorDamageReduction;

    static const int nbrQuotes = 5;
    static std::string quotes[FragTrap::nbrQuotes];
public:
    FragTrap(const std::string &name); //참조변수를 매개변수로 받는 생성자 래퍼런스변수란 복사본을 전달하지 않고 마치 포인터처럼
    // 전달되지만 바로 값으로 사용가능하다.
    FragTrap(const FragTrap &other); //복사 생성자 자기 자신을 매개변수로 받음 만약에 타입 const 래퍼변수가 아니면 무한루프에 빠질수도!
    virtual ~FragTrap(); // 소멸자 상속을 사용하는 경우 문제가 생기는 점을 방지하기 위해 virtual로 지정 부모 타입 = 자식 객체의
    // 경우 부모를 딜리트하는 경우 자식 객체 내용이 남아서 메모리 누수 발생 할 수 있다.

    FragTrap &operator=(const FragTrap &other); // 할당 연산자에 관한 오버로딩이다. 우측에 할당한 내용을 상수 참조로 받는 것은 명확한데
    // 왼쪽에 있는 내용을 바꾸고 싶은 것이지 할당 오른쪽은 변경을 원하지 않기 때문입니다.

    void meleeAttack(std::string const &target);
    void rangedAttack(std::string const &target);
    bool takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void vaulthunter_dot_exe(std::string const &target);
};


#endif //CPP_FRAGTRAP_HPP
