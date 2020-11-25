//
// Created by namhyung kim on 2020/11/24.
//

#ifndef CPP_SCAVTRAP_HPP
#define CPP_SCAVTRAP_HPP

# include <iostream>
# include <string>

class ScavTrap {
private:
    ScavTrap();

    std::string name;
    int level;
    int hitPoints;
    int maxHitPoints;
    int energyPoints;
    int maxEnergyPoints;
    int meleeAttackDamage;
    int rangedAttackDamage;
    int armorDamageReduction;

    static const int nbrChalls = 5;
    static std::string challenges[ScavTrap::nbrChalls];
public:
    ScavTrap(std::string const &name);
    ScavTrap(ScavTrap const &other);
    virtual ~ScavTrap();

    ScavTrap &operator=(ScavTrap const &other);

    void meleeAttack(std::string const &target);
    void rangedAttack(std::string const &target);
    bool takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void challengeNewcomer(void);
};


#endif //CPP_SCAVTRAP_HPP
