//
// Created by namhyung kim on 2020/11/23.
//

#ifndef CPP_FRAGTRAP_HPP
#define CPP_FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
private:
    FragTrap();
protected:
    static const int nbrQuotes = 5;
    static std::string quotes[FragTrap::nbrQuotes];
public:
    FragTrap(std::string const &name);
    FragTrap(FragTrap const &other);
    virtual ~FragTrap();

    FragTrap &operator=(FragTrap const &other);

    void meleeAttack(std::string const &target);
    void rangedAttack(std::string const &target);
    void vaulthunter_dot_exe(std::string const &target);
};


#endif //CPP_FRAGTRAP_HPP
