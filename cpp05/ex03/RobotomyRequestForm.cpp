//
// Created by namhyung kim on 2020/11/03.
//

#include "RobotomyRequestForm.hpp"

std::string const &RobotomyRequestForm::name = std::string("Robotomy Request");

RobotomyRequestForm::RobotomyRequestForm(std::string const &target):Form(RobotomyRequestForm::name, 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other):Form(other), target(other.target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	(void)other;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	Form::execute(executor);
	std::cout << "* VRRRRR BZZZZZZ VRRRRRR *" << std::endl;
	if ((rand() % 100) > 50)
		std::cout << this->target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->target << " robotomization is a failure" << std::endl;
}

Form *RobotomyRequestForm::generate(std::string const &target)
{
	return (new RobotomyRequestForm(target));
}
