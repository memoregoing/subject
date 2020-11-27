//
// Created by namhyung kim on 2020/11/04.
//

#include <iostream>
#include "Interpreter.hpp"

int main(int argc, char const *argv[])
{
    // 알규먼트가 없으면 error
	if (argc != 2)
	{
		std::cout << "convert: error: bad arguments\n"
				<< "         usage: value" << std::endl;
	}
	else
	{
	    // 알규먼트가 있다면 그것으로 interpreter 객체 p를 생성
	    // 생성자를 이용하여 p를 초기화 한다.
	    // 그리고 std::cout를 이용하여 결과값을 프린트한다.
		Interpreter p(argv[1]);
		std::cout << p << std::endl;
	}
	return (0);
}
