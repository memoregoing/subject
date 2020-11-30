//
// Created by namhyung kim on 2020/11/29.
//

#include "easyfind.hpp"

int main(void)
{
	{
		std::vector<int> vec(5, 5);
		for (int i = 0; i < 5; i++)
			vec[i] = i;
		std::vector<int>::iterator found = easyfind(vec, 3);
		if (found == vec.end())
			std::cout << "숫자를 찾지 못했어요!" << std::endl;
		else
			std::cout << "숫자 " << *found << " 찾았지비" << std::endl;
		if (easyfind(vec, 42) == vec.end())
			std::cout << "42는 죽었다" << std::endl;
	}
	return (0);
}
