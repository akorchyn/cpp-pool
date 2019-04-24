#ifndef HELPER_EVALEXPR_HPP
#define HELPER_EVALEXPR_HPP

#include <iostream>
#include "Fixed.hpp"
#include <string>
#include <sstream>

std::string		parseToPolishNotation(const std::string &x);
void			error(std::string error);

#endif
