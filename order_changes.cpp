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

void order_by_priority(std::multimap<int, task, std::greater<int>>& priority_mmap){

    std::ofstream output_file("todolist.txt");

    if (output_file.is_open()) {

        for ( auto& coppia : priority_mmap){
            output_file << coppia.second;
        }


    } else {
        std::cerr << "Unable to open file\n";
    }

    output_file.flush();
    output_file.close();

}

void order_by_status(std::multimap<int, task, std::greater<int>>& status_mmap){

    std::ofstream output_file("todolist.txt");

    if (output_file.is_open()) {

        for ( auto& coppia : status_mmap){
            output_file << coppia.second;
        }


    } else {
        std::cerr << "Unable to open file\n";
    }

    output_file.flush();
    output_file.close();

}

void order_by_title(std::map<string, task>& title_map){

    std::ofstream output_file("todolist.txt");

    if (output_file.is_open()) {

        for ( auto& coppia : title_map){
            output_file << coppia.second;
        }


    } else {
        std::cerr << "Unable to open file\n";
    }

    output_file.flush();
    output_file.close();

}

void order_by_date(std::multimap<date, task, std::greater<date>>& date_mmap){

    std::ofstream output_file("todolist.txt");


    if (output_file.is_open()) {

        for ( auto& coppia : date_mmap){
            output_file << coppia.second;

        }


    } else {
        std::cerr << "Unable to open file\n";
    }

    output_file.flush();
    output_file.close();

}
