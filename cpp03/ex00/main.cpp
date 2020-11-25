//
// Created by namhyung kim on 2020/11/24.
//

#include "FragTrap.hpp"

int main(void)
{
    FragTrap frag("FR4G");

    srand(time(NULL));
    // 난수 생성을 위한 시드를 추가한다. 원래는 시드를 생성하지 않으면 같은 수를 보내기 때문에 항사 같은 값을 얻게 된다.
    // 씨드값으로 현재시간을 넣어 주게 된다.
    frag.vaulthunter_dot_exe("CL4P-TP");
    frag.meleeAttack("CL4P-TP");
    frag.rangedAttack("CL4P-TP");
    frag.takeDamage(24);
    frag.beRepaired(50);
    frag.takeDamage(42);
    frag.takeDamage(100);
    frag.beRepaired(125);
    frag.vaulthunter_dot_exe("CL4P-TP");
    frag.vaulthunter_dot_exe("CL4P-TP");
    frag.vaulthunter_dot_exe("CL4P-TP");
    frag.vaulthunter_dot_exe("CL4P-TP");
    return (0);
}