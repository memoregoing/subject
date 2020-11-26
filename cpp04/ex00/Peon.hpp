//
// Created by namhyung kim on 2020/11/25.
//

#ifndef CPP_PEON_HPP
#define CPP_PEON_HPP

# include "Victim.hpp"

class Peon: public Victim {
private:
    Peon();
public:
    Peon(std::string const &name);
    Peon(Peon const &peon);
    virtual ~Peon();

    Peon &operator=(const Peon& other);

    void getPolymorphed(void) const;
};


#endif //CPP_PEON_HPP
