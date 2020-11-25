//
// Created by namhyung kim on 2020/11/25.
//

#ifndef CPP_NINJATRAP_HPP
#define CPP_NINJATRAP_HPP

#include <string>
#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap: virtual public ClapTrap
{
private:
    NinjaTrap();
public:
    NinjaTrap(std::string const &name);
    NinjaTrap(NinjaTrap const &other);
    virtual ~NinjaTrap();

    NinjaTrap &operator=(NinjaTrap const &other);

    void meleeAttack(std::string const &target);
    void rangedAttack(std::string const &target);
    void ninjaShoebox(FragTrap &trap);
    void ninjaShoebox(ScavTrap &trap);
    void ninjaShoebox(ClapTrap &trap);
    void ninjaShoebox(NinjaTrap &trap);
};


#endif //CPP_NINJATRAP_HPP
