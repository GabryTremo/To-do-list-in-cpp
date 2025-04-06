#ifndef ORDER_CHANGES_H_INCLUDED
#define ORDER_CHANGES_H_INCLUDED

#include "date.h"
#include "task.h"
#include "operator_overloads.h"

#include <iostream>
#include <string>

#include <algorithm>
#include <map>

#include <fstream>

using std::cout, std::cin, std::string;

void order_by_priority(std::multimap<int, task, std::greater<int>>&);

void order_by_status(std::multimap<int, task, std::greater<int>>&);

void order_by_title(std::map<string, task>&);

void order_by_date(std::multimap<date, task, std::greater<date>>&);

#endif // ORDER_CHANGES_H_INCLUDED
