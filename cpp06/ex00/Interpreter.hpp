//
// Created by namhyung kim on 2020/11/04.
//

#ifndef INTERPRETER_HPP
# define INTERPRETER_HPP

# include <iostream>
# include <iomanip>
# include <sstream>
# include <string>
# include <cctype>
# include <cmath>
# include <limits>

class Interpreter
{
private:
	Interpreter();

	std::string str;
	int type;

	int status[4];
	int ivalue;
	float fvalue;
	double dvalue;
	char cvalue;

	void parse(void);

	void convert(void);
	void fromInt(void);
	void fromFloat(void);
	void fromDouble(void);
	void fromChar(void);

	void setFlag(int status, int flag);
    // 열겨형으로 char == 0 이고 차례대로 값이 1씩증가한다
	enum Type {
		TypeChar, // 0
		TypeInt, // 1
		TypeFloat, // 2
		TypeDouble, // 3
		TypeLong, // 4
		TypeInvalid //5
	};
public:
	Interpreter(std::string const &value); // 생성자로 string 타입의 래퍼런스 변수를 받아 클래스의 인스턴스를 만든다.
	Interpreter(Interpreter const &other); // 복사 생성자로 매개변수로 이 클레스의 인스턴스를 받을 때 사용된다.
	virtual ~Interpreter(); //소멸자로 이 클레스의 객체를 delete 할때 사용한다.
    // 스테틱 컨스트이므로 클레스가 메모리에 적재 될때 초기화 되고 클래스의 모든 인스턴스가 공유하고 변경 할 수 없다.
	static const int isImpossible = 0x00000001; // 16진수로 10진수로 변환하면 1
	static const int nonDisplayable = 0x00000010; // 16진수로 10진수로 변환하면 16

	Interpreter &operator=(Interpreter const &other); // 대입 연산자의 오버로딩으로
	// 사용자가 정의한 클레스에 관한 대입연산자를 사용하기 위해 사용 된다.

	bool floatIsValue(void) const;
	bool doubleIsValue(void) const;
	bool hasFlag(int status, int flag) const;

	int getAsInt(void) const;
	float getAsFloat(void) const;
	double getAsDouble(void) const;
	char getAsChar(void) const;
	std::string const &getRaw(void) const;
};

std::ostream &operator<<(std::ostream &out, Interpreter const &pr);
// << 연산자는 클레스 밖에서 정의 해줘야 한다고 한다.
// << 오른쪽 자리에 interpreter 객체가 왔을때의 행동을 정의 합니다.

#endif
