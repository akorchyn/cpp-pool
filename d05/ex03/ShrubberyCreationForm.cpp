#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
	: Form("Shrubbery Creation", 145, 137)
{
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &x)
	: Form(x)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &x)
{
	if (&x == this)
		return *this;
	Form::operator=(x);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const &x) const
{
	Form::execute(x);

	std::ofstream	file(_target);
	if (!file.good())
		throw std::runtime_error("File error");
	file << "                     - - -\n"
			"                   -        -  -     --    -\n"
			"                -                 -         -  -\n"
			"                                -\n"
			"                               -                --\n"
			"               -          -            -              -\n"
			"               -            '-,        -               -\n"
			"               -              'b      *\n"
			"                -              '$    #-                --\n"
			"               -    -           $:   #:               -\n"
			"             --      -  --      *#  @):        -   - -\n"
			"                          -     :@,@):   ,-**:'   -\n"
			"              -      -,         :@@*: --**'      -   -\n"
			"                       '#o-    -:(@'-@*\"'  -\n"
			"               -  -       'bq,--:,@@*'   ,*      -  -\n"
			"                          ,p$q8,:@)'  -p*'      -\n"
			"                   -     '  - '@@Pp@@*'    -  -\n"
			"                    -  - --    Y7'.'     -  -\n"
			"                              :@):.\n"
			"                             .:@:'.\n"
			"                           .::(@:.   \n";
}
