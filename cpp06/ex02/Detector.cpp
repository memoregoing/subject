//
// Created by namhyung kim on 2020/11/04.
//
#include "Detector.hpp"

Base *generate(void)
{
	int r = rand() % 100;

	if (r > 66)
		return (new A);
	if (r > 33)
		return (new B);
	return (new C);
}
// dynamic_cast는 safe downcasting(안전한 업 다운캐스팅)에 사용이 됩니다.
// 부모 클래스의 포인터에세 자식 클래스의 포인터로 업 다운 캐스팅 해주는 연산자 입니다.
// 타입이 맞지 않으면 캐스팅 과정에서 null로 바뀌는걸 이용해서 타입 추론
void identify_from_pointer(Base *p)
{
	if (dynamic_cast<A*>(p) != nullptr)
		std::cout << "A";
	else if (dynamic_cast<B*>(p) != nullptr)
		std::cout << "B";
	else if (dynamic_cast<C*>(p) != nullptr)
		std::cout << "C";
}

void identify_from_reference(Base &p)
{
	identify_from_pointer(&p);
}
