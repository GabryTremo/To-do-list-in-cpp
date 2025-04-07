#ifndef CONVERSIONS_H_INCLUDED
#define CONVERSIONS_H_INCLUDED

#include "date.h"

#include <iostream>
#include <string>

using std::cout, std::cin, std::string;

// Per convertire il numero da 0 a 5 della priorità nelle stringhe corrispondenti
string int_to_priority_name(int);

// Viceversa. Non si può fare con switch perche prende solo interi
int priority_name_to_int(string);

// Per convertire il numero -1, 0 o 1 della priorità nelle stringhe corrispondenti
string int_to_status_name(int);

// Viceversa. Non si può fare con switch perche prende solo interi
int status_name_to_int(string);

// Per convertire la stinga nella forma dd/mm/yyyy in un oggetto della classe date (quindi 3 interi)
date string_to_date(string);

#endif // CONVERSIONS_H_INCLUDED
