//
// Created by namhyung kim on 2020/11/25.
//

#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

# include <iostream>
# include <string>
# include "NinjaTrap.hpp"
# include "FragTrap.hpp"

class SuperTrap: public NinjaTrap, public FragTrap
{
private:
    SuperTrap();
public:
    SuperTrap(std::string const &name);
    SuperTrap(SuperTrap const &other);
    virtual ~SuperTrap();

    SuperTrap &operator=(SuperTrap const &other);

    void rangedAttack(std::string const &target);
    void meleeAttack(std::string const &target);
};

#endif //CPP_SUPERTRAP_HPP
