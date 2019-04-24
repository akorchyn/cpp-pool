#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try {
		Form("Legkie narkotiki", 50, 10050);
	}
	catch (std::exception &x)
	{
		std::cout << x.what() << std::endl;
	}
	try {
		Form("Legkie narkotiki", 0, 100);
	}
	catch (std::exception &x)
	{
		std::cout << x.what() << std::endl;
	}
	try {
		Form form("Legkie narkotiki", 50, 100);
		Bureaucrat x("Artur", 1);
		Bureaucrat y("Kostyan", 51);

		x.signForm(form);
		y.signForm(form);
		form.beSigned(y);
	}
	catch (std::exception &x)
	{
		std::cout << x.what() << std::endl;
	}

}