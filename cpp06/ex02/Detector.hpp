//
// Created by namhyung kim on 2020/11/04.
//

#ifndef DETECTOR_HPP
# define DETECTOR_HPP

# include <iostream>
# include <random>
# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base *generate(void);

void identify_from_pointer(Base *p);
void identify_from_reference(Base &p);

#endif
