//
// Created by namhyung kim on 2020/11/29.
//

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <list>
# include <vector>
# include <set>
# include <cmath>
# include <algorithm>

// multiset의 특징
// set container와 달리 중복 된 key값을 저장 할 수 있다.
// 연관 컨테이너의의 종류이며 데이터를 일정 규칙에 따라 조직하고 관리하는 컨테이너 입니다.
class Span
{
private:
	Span();

	size_t max;
	// 선언 방법은 multiset<데이터 타입> 변수이름 입니다.
	std::multiset<int> numbers;
public:
	Span(size_t amount);
	Span(Span const &other);
	virtual ~Span();

	class FullSpanException: public std::exception {
		virtual const char* what() const throw();
	};
	class NotEnoughNumbersException: public std::exception {
		virtual const char* what() const throw();
	};

	Span &operator=(Span const &other);

	void addNumber(int value);
	// 템플릿 함수는 헤더에서 정의 할 수 있도록 예외 사항이라 이부분은 여기서 정의하였습니다.
	// 즉, header파일에 함수 템플릿를 선언하고 cpp 파일에 함수 템플릿의 구현을 작성하면 링크 error가 발생하다.
	template<typename InputIterator>
	void addNumber(InputIterator begin, InputIterator end) {
        if (this->numbers.size() + std::distance(begin, end) > this->max)
            throw Span::FullSpanException();
        this->numbers.insert(begin, end);
	};

	size_t shortestSpan(void) const;
	size_t longestSpan(void) const;
};

#endif
