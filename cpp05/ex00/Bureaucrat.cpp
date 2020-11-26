//
// Created by namhyung kim on 2020/11/03.
//

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const &name, int grade):name(name), grade(grade)
{
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
	// c++에서 명시적으로 예외가 발생 하였다는 것을 나타 낼 수 있는 thorw을 사용 합니다.
	// throw 하고 예외로 전달하고 싶은 객체를 쓰면 됩니다.
	// 표준 라이브러리에도 에러가 정의되어 있어서 그것을 활용 할 수 있습니다.
	// throw하게 되면 즉스 함수가 종료되고 예외 처리하는 부분까지 점프하게 됩니다. 그말은
	// throw 아래의 부분을 실행하지 않는다는 것 입니다.
	// 중요한 점은 throw을 발생하면 예외 처리하는 부분에 도달하기 전까지 함수를 빠져나가면서 stack에 생성된 객체를 소멸시켜줍니다.
}

Bureaucrat::Bureaucrat(Bureaucrat const &other):name(other.name), grade(other.grade)
{
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
}
// 중첩 클레스로 exception 클레스를 상속 받아서 에러처리
// 왜 이런 에러 처리를 하게 되냐면 클레스에 따라 잡힌 예외를 던질 수 있기 때문입니다.
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "BureaucratException: Grade too High";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "BureaucratException: Grade too Low";
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
	this->grade = other.grade;
	return (*this);
}

std::string const &Bureaucrat::getName(void) const
{
	return (this->name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

void Bureaucrat::incrementGrade(void)
{
	this->grade--;
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade(void)
{
	this->grade++;
	if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	out << "Bureaucrat " << bureaucrat.getName() << " (Grade " << bureaucrat.getGrade() << ")";
	return (out);
}
