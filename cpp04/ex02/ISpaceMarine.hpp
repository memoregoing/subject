//
// Created by namhyung kim on 2020/11/25.
//

#ifndef ISPACEMARINE_HPP
# define ISPACEMARINE_HPP

# include <iostream>

//인터페이스 클래스
//소멸자와 순수 가상함수만으로 선언된 클래스를 뜻합니다.
//interface myclass 라고 interface라는 키워드를 사용 할 수 있지만 뭘로 선언 하든 순수 가상함수들만 구성 되어 있다면
//작용은 동일하다고 합니다.
class ISpaceMarine
{
public:
	virtual ~ISpaceMarine() {} // 꼭 선언하지 않아도 된다고 해요 상속에서 객체 삭제 할때 문제가 생길때도 있어요
	virtual ISpaceMarine *clone(void) const = 0; //함수의 선언과 virtual을 통해 가상함수임을 알 수 있습니다.
	virtual void battleCry(void) const = 0;
	virtual void rangedAttack(void) const = 0;
	virtual void meleeAttack(void) const = 0;
};

#endif
