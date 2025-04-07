#include "order_changes.h"
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
void order_by_priority(std::multimap<int, task, std::greater<int>>& priority_mmap){

    std::ofstream output_file("todolist.txt");

    if (output_file.is_open()) {

        for (auto& coppia : priority_mmap){
            output_file << coppia.second;
        }

    } else {
        std::cerr << "Unable to open file\n";
    }

    // Probabilmente non necessario, inserito solo per sicurezza
    output_file.flush();
    output_file.close();

}

// Ordina per status decrescente la lista nel file .txt (la mappa è già ordinata così di default).
// L'ordine è: da completare, completato, scaduto.
void order_by_status(std::multimap<int, task, std::greater<int>>& status_mmap){

    std::ofstream output_file("todolist.txt");

    if (output_file.is_open()) {

        for (auto& coppia : status_mmap){
            output_file << coppia.second;
        }

    } else {
        std::cerr << "Unable to open file\n";
    }

    // Probabilmente non necessario, inserito solo per sicurezza
    output_file.flush();
    output_file.close();

}

// Ordina in ordine alfabetico la lista nel file .txt (la mappa è già ordinata così di default).
void order_by_title(std::map<string, task>& title_map){

    std::ofstream output_file("todolist.txt");

    if (output_file.is_open()) {

        for (auto& coppia : title_map){
            output_file << coppia.second;
        }

    } else {
        std::cerr << "Unable to open file\n";
    }

    // Probabilmente non necessario, inserito solo per sicurezza
    output_file.flush();
    output_file.close();

}

// Ordina per data di scadenza decrescente la lista nel file .txt (la mappa è già ordinata così di default).
// Nota: forse ha più senso per data di scadenza crescente, però così quelli scaduti sarebbero in cima finchè non sono eliminati.
void order_by_date(std::multimap<date, task, std::greater<date>>& date_mmap){

    std::ofstream output_file("todolist.txt");

    if (output_file.is_open()) {

        for (auto& coppia : date_mmap){
            output_file << coppia.second;

        }

    } else {
        std::cerr << "Unable to open file\n";
    }

    // Probabilmente non necessario, inserito solo per sicurezza
    output_file.flush();
    output_file.close();

}
