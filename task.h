#ifndef TASK_H
#define TASK_H

#include "date.h"
#include <string>


class task
{
    public:
        task();
        task(std::string, date, int, int);
        task(std::string, std::string, date, int, int);

        std::string Gettitle() { return title; }
        void Settitle(std::string val) { title = val; }
        std::string Getdescription() { return description; }
        void Setdescription(std::string val) { description = val; }
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
        std::string title;
        std::string description;
        date due_date;
        int priority;
        int status;
};

#endif // TASK_H
