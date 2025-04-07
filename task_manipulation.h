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

// Funzione che restituisce true se la riga successiva a quella attuale (passata in input) del file passato
// in input è vuota, e false altrimenti.
bool next_line_empty_check(std::ifstream&, std::streampos);

// Funzione che iempie le 4 mappe a partire dal file .txt
void fill_mmaps(std::multimap<int, task, std::greater<int>>&, std::multimap<int, task, std::greater<int>>&,
                std::map<string, task>&, std::multimap<date, task, std::greater<date>>&);

// Funzione che aggiunge un task, specificato dall'utente, alle varie mappe e al file .txt
void add_task(std::multimap<int, task, std::greater<int>>&, std::multimap<int, task, std::greater<int>>&,
              std::map<string, task>&, std::multimap<date, task, std::greater<date>>&);

// Funzione che rimuove un task, specificato dall'utente, dalle varie mappe e dal file .txt
void delete_task(std::multimap<int, task, std::greater<int>>&, std::multimap<int, task, std::greater<int>>&,
                 std::map<string, task>&, std::multimap<date, task, std::greater<date>>&);

// Funzione che cambia lo status (da "pending" a "completed" o viceversa) di un task selezionato dall'utente,
// e poi aggiorna le mappe e il file .txt
void edit_status(std::multimap<int, task, std::greater<int>>&, std::multimap<int, task, std::greater<int>>&,
                 std::map<string, task>&, std::multimap<date, task, std::greater<date>>&);

// Funzione per segnare automaticamente come scaduti i task che hanno data precedente ad oggi.
void update_expired(std::multimap<int, task, std::greater<int>>&, std::multimap<int, task, std::greater<int>>&,
                    std::map<string, task>&, std::multimap<date, task, std::greater<date>>&);

// Funzione per rimuovere automaticamente i task segnati come scaduti
void delete_expired(std::multimap<int, task, std::greater<int>>&, std::multimap<int, task, std::greater<int>>&,
                    std::map<string, task>&, std::multimap<date, task, std::greater<date>>&);

#endif // TASK_MANIPULATION_H_INCLUDED
