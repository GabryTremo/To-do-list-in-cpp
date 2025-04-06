#ifndef OPERATOR_OVERLOADS_H_INCLUDED
#define OPERATOR_OVERLOADS_H_INCLUDED

#include "conversions.h"
#include "date.h"
#include "task.h"

#include <iostream>
#include <string>

#include <fstream>

using std::cout, std::cin, std::string;

std::ostream& operator<<(std::ostream&, date&);

std::ostream& operator<<(std::ostream&, task&);

#endif // OPERATOR_OVERLOADS_H_INCLUDED
