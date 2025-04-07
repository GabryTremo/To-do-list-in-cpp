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

// Ordina per priorit� decrescente la lista nel file .txt (la mappa � gi� ordinata cos� di default)
void order_by_priority(std::multimap<int, task, std::greater<int>>&);

// Ordina per status decrescente la lista nel file .txt (la mappa � gi� ordinata cos� di default).
// L'ordine �: da completare, completato, scaduto.
void order_by_status(std::multimap<int, task, std::greater<int>>&);

// Ordina in ordine alfabetico la lista nel file .txt (la mappa � gi� ordinata cos� di default).
void order_by_title(std::map<string, task>&);

// Ordina per data di scadenza decrescente la lista nel file .txt (la mappa � gi� ordinata cos� di default).
// Nota: forse ha pi� senso per data di scadenza crescente, per� cos� quelli scaduti sarebbero in cima finch� non sono eliminati.
void order_by_date(std::multimap<date, task, std::greater<date>>&);

#endif // ORDER_CHANGES_H_INCLUDED
