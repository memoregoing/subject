//
// Created by namhyung kim on 2020/11/04.
//

#include "Data.hpp"

void *serialize(void)
{
	static std::string alphabet = "0123456789" \
		"abcdefghijklmopqrstuvxyz" \
		"ABCDEFGHIJKLMOPQRSTUVXYZ";
	static size_t alphabetLength = alphabet.length();
	char *raw;

	raw = new char[20];
	for (int i = 0; i < 8; i++)
		raw[i] = alphabet[rand() % alphabetLength];
	//클래스가 서로 관련되어 있는지 여부에 관계없이 모든 유형의 다른 포인터의 포인터를 변환하는 데 사용됩니다.
	// 포인터가 가리키는 포인터 타입과 데이터가 같은지 확인하지 않습니다.
	// 비트 단위로 재해석한다.
	*reinterpret_cast<int*>(raw + 8) = rand() % 424242;
	// 타입캐스팅을 통해 주소값 + 8 자리에 랜덤 인트값을 집어 넣습니다.
	for (int i = 0; i < 8; i++)
		raw[i + 12] = alphabet[rand() % alphabetLength];
	// 다시 문자열을 집어 넣어요!
	return (raw);
}

Data *deserialize(void *raw)
{
	Data *d = new Data;

	d->s1 = std::string(static_cast<char*>(raw), 8);
	// 다른 포인터 유형으로 변경하기 때문에 reinterpret_cast를 사용 합니다.
	d->n = *reinterpret_cast<int*>(static_cast<char*>(raw) + 8);
	// 이 부분부터 인트로 표
	d->s2 = std::string(static_cast<char*>(raw) + 12, 8);
	// 다시 이 부분을 string으로 표현 8번째 자리까지!
	return (d);
}
