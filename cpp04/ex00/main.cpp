//
// Created by namhyung kim on 2020/11/25.
//

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"

//다형성(polymorphism)이란 하나의 객체가 여러 가지 타입을 가질 수 있는 것을 의미합니다.
//이러한 다형성을 부모 클래스 타입의 참조 변수로 자식 클래스 타입의 인스턴스를 참조할 수 있도록 하여 구현하고 있는 것을 보는 것입니다.

int main(void)
{
    Sorcerer robert("Robert", "the Magnificent");
    Victim jim("Jimmy");
    Peon joe("Joe");
    std::cout << robert << jim << joe;
    // 여기서 보면 Victim은 부모 클레스이고 Peon은 자식 클레스입니다.
    // 하지만 Sorcerer 클레스의 매개변수는 Victim이지만 자식 클래스의 인스턴스도 제대로 작동 하는것을 볼 수 있어요!
    robert.polymorph(jim);
    robert.polymorph(joe);
    return 0;
}