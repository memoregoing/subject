//
// Created by namhyung kim on 2020/11/04.
//

#include <iostream>
#include "Detector.hpp"

int main(void)
{
	srand(time(NULL));

	for (int i = 0; i < 50; i++)
	{
		Base *o = generate();
		std::cout << "Test " << i << ": ";
		identify_from_pointer(o);
		std::cout << ", ";
		// 래퍼런스변수로 받기 위해 *를 통해 원래의 값으로 변경하는 과정입니다.
		identify_from_reference(*o);
		std::cout << std::endl;
		delete o;
	}

	return (0);
}
