//
// Created by namhyung kim on 2020/11/25.
//

#ifndef CPP_SORCERER_HPP
#define CPP_SORCERER_HPP

# include <iostream>
# include <string>
# include "Victim.hpp"

class Sorcerer {
private:
    Sorcerer();

    std::string name;
    std::string title;
public:
    Sorcerer(std::string const &name, std::string const &title);
    Sorcerer(const Sorcerer& other);
    virtual ~Sorcerer();

    Sorcerer &operator=(const Sorcerer& other);

    std::string const &getName(void) const;
    std::string const &getTitle(void) const;

    void polymorph(Victim const &victim) const;
};

std::ostream &operator<<(std::ostream &out, Sorcerer const &sorcerer);

#endif //CPP_SORCERER_HPP
