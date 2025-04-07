#ifndef OPERATOR_OVERLOADS_H_INCLUDED
#define OPERATOR_OVERLOADS_H_INCLUDED

#include "conversions.h"
#include "date.h"
#include "task.h"

#include <iostream>
#include <string>

#include <fstream>

using std::cout, std::cin, std::string;

// Sovraccarica l'operatore << in modo da far stampare date nel modo voluto
std::ostream& operator<<(std::ostream&, date&);

// Stessa cosa ma con l'operatore << per task anzichè date
std::ostream& operator<<(std::ostream&, task&);

#endif // OPERATOR_OVERLOADS_H_INCLUDED
