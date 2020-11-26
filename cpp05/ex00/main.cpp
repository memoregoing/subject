//
// Created by namhyung kim on 2020/11/03.
//

#include <iostream>
#include "Bureaucrat.hpp"

// 씨언어에서의 error처리 방식
// if (c == NULL) {
// printf("Error");
// return ;
// }
// 에러처리의 양이 늘어 날수록 if문이 증가하게 됩니다. 그리고 언어 자체에서 지원하는 Error처리가 존재하지 않아요.

int main(void)
{
	Bureaucrat francis("Francis", 100);
	std::cout << francis << std::endl;
	francis.incrementGrade();
	std::cout << francis << std::endl;
	francis.decrementGrade();
	std::cout << francis << std::endl;
    // 예외가 발생 할 것 같은 부분을 try에서 실행하게 됩니다.
    // 만약에 예외가 발생하지 않는다면 try, catch가 없는 것처럼 작동 합니다.
    // 마치 C언어에서 if (조건실행) {본문} 이렇게해서 조건은 꼭 실행하는 것과
    // 비슷하게 작동 한다고 보면 됩니다.
	try
	{
		Bureaucrat jack("Jack", 0);
		std::cout << jack << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	// 만약 에러가 발생하면 std에서 익셉션 객체로 받아서 처리하겠다는 부분입니다.
	// e.what()를 통해 설명 문자열을 반환 받습니다.
	// 설명 정보가 있는 널이 끝나는 문자열에 대한 포인터를 반환 받습니다.
	// 적어도 획득한 예외 객체가 소멸되거나 예외 객체의 상수가 아닌 맴버 함수가 호출 될때까지 유효하다고 합니다.

	try
	{
		Bureaucrat jack("Jack", 1000);
		std::cout << jack << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat jack("Jack", 1);
		std::cout << jack << std::endl;
		jack.incrementGrade();
		std::cout << jack << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat jack("Jack", 150);
		std::cout << jack << std::endl;
		jack.decrementGrade();
		std::cout << jack << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
