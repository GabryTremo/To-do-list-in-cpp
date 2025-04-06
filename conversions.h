#ifndef CONVERSIONS_H_INCLUDED
#define CONVERSIONS_H_INCLUDED

#include "date.h"

#include <iostream>
#include <string>

using std::cout, std::cin, std::string;

string int_to_priority_name(int);

int priority_name_to_int(string);

string int_to_status_name(int);

int status_name_to_int(string);

date string_to_date(string);

#endif // CONVERSIONS_H_INCLUDED
