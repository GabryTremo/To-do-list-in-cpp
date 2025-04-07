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

// Ordina per priorità decrescente la lista nel file .txt (la mappa è già ordinata così di default)
void order_by_priority(std::multimap<int, task, std::greater<int>>&);

// Ordina per status decrescente la lista nel file .txt (la mappa è già ordinata così di default).
// L'ordine è: da completare, completato, scaduto.
void order_by_status(std::multimap<int, task, std::greater<int>>&);

// Ordina in ordine alfabetico la lista nel file .txt (la mappa è già ordinata così di default).
void order_by_title(std::map<string, task>&);

// Ordina per data di scadenza decrescente la lista nel file .txt (la mappa è già ordinata così di default).
// Nota: forse ha più senso per data di scadenza crescente, però così quelli scaduti sarebbero in cima finchè non sono eliminati.
void order_by_date(std::multimap<date, task, std::greater<date>>&);

#endif // ORDER_CHANGES_H_INCLUDED
