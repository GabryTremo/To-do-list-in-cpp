#ifndef TASK_MANIPULATION_H_INCLUDED
#define TASK_MANIPULATION_H_INCLUDED

#include "date.h"
#include "task.h"
#include "conversions.h"
#include "order_changes.h"
#include "operator_overloads.h"

#include <iostream>
#include <string>

#include <algorithm>
#include <map>

#include <fstream>

#include <limits>

using std::cout, std::cin, std::string;

bool next_line_empty_check(std::ifstream&, std::streampos);

void fill_mmaps(std::multimap<int, task, std::greater<int>>&, std::multimap<int, task, std::greater<int>>&,
                std::map<string, task>&, std::multimap<date, task, std::greater<date>>&);

void add_task(std::multimap<int, task, std::greater<int>>&, std::multimap<int, task, std::greater<int>>&,
              std::map<string, task>&, std::multimap<date, task, std::greater<date>>&);

void delete_task(std::multimap<int, task, std::greater<int>>&, std::multimap<int, task, std::greater<int>>&,
                 std::map<string, task>&, std::multimap<date, task, std::greater<date>>&);

void edit_status(std::multimap<int, task, std::greater<int>>&, std::multimap<int, task, std::greater<int>>&,
                 std::map<string, task>&, std::multimap<date, task, std::greater<date>>&);

void update_expired(std::multimap<int, task, std::greater<int>>&, std::multimap<int, task, std::greater<int>>&,
                    std::map<string, task>&, std::multimap<date, task, std::greater<date>>&);

void delete_expired(std::multimap<int, task, std::greater<int>>&, std::multimap<int, task, std::greater<int>>&,
                    std::map<string, task>&, std::multimap<date, task, std::greater<date>>&);

#endif // TASK_MANIPULATION_H_INCLUDED
