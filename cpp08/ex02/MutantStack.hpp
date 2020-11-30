//
// Created by namhyung kim on 2020/11/29.
//

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>

// 스텍을 다시 한번 사용지 지정 클레스로 래핑 하는 방법이다.
// 이러한 기법은 추후에 원시형태에 관해 존재 하지 않으면 NULL을 반환받기 위해 이런식으로 쓰인다더라
template<typename T>
class MutantStack: public std::stack<T>
{
public:
	MutantStack();
	MutantStack(MutantStack<T> const &other);
	virtual ~MutantStack();
    // const 타입과 비 const타입을 모두 지정해준다고 합니다.
    // 왜 같은게 두개인지 궁금해 하실 텐데 변수의 타입에 따라 다른 함수가 작동 합니다.
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	MutantStack<T> &operator=(MutantStack<T> const &other);

	iterator begin(void);
	const_iterator begin(void) const;
	reverse_iterator rbegin(void);
	const_reverse_iterator rbegin(void) const;
	iterator end(void);
	const_iterator end(void) const;
	reverse_iterator rend(void);
	const_reverse_iterator rend(void) const;
};
// 템플릿 함수의 경우
// 컴파일 과정중에 선언부와 구현부가 있지 않으면 링킹 error를 발생시킨다.
// hpp에 선언하고 cpp에 구현하면 그러한 에러가 발생한다.
# include "MutantStack.ipp"

#endif
