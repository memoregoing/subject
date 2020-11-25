//
// Created by namhyung kim on 2020/11/24.
//

#ifndef CPP_SCAVTRAP_HPP
#define CPP_SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
private:
    ScavTrap();
protected:
    static const int nbrChalls = 5;
    static std::string challenges[ScavTrap::nbrChalls];
public:
    ScavTrap(std::string const &name);
    ScavTrap(ScavTrap const &other);
    virtual ~ScavTrap();

    ScavTrap &operator=(ScavTrap const &other);

    void meleeAttack(std::string const &target);
    void rangedAttack(std::string const &target);
    void challengeNewcomer(void);
};

#endif //CPP_SCAVTRAP_HPP
