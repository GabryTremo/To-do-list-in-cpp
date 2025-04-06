#ifndef TASK_H
#define TASK_H

#include "date.h"
#include <iostream>
#include <string>


using std::cout, std::cin, std::string;


class task
{
    public:
        task();
        task(string, date, int, int);
        task(string, string, date, int, int);

        string Gettitle() { return title; }
        void Settitle(string val) { title = val; }
        string Getdescription() { return description; }
        void Setdescription(string val) { description = val; }
        date Getdue_date() { return due_date; }
        void Setdue_date(date val) { due_date = val; }
        int Getpriority() { return priority; }
        void Setpriority(int val) { priority = val; }
        int Getstatus() { return status; }
        void Setstatus(int val) { status = val; }

        bool is_expired(){
            return due_date.is_expired();
        }


    protected:

    private:
        string title;
        string description;
        date due_date;
        int priority;
        int status;
};

#endif // TASK_H
