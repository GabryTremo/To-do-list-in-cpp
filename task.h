#ifndef TASK_H
#define TASK_H

#include "date.h"
#include <string>


class task
{
    public:
        task();
        task(std::string, date, int, bool);
        task(std::string, std::string, date, int, bool);

        std::string Gettitle() { return title; }
        void Settitle(std::string val) { title = val; }
        std::string Getdescription() { return description; }
        void Setdescription(std::string val) { description = val; }
        date Getdue_date() { return due_date; }
        void Setdue_date(date val) { due_date = val; }
        int Getpriority() { return priority; }
        void Setpriority(int val) { priority = val; }
        bool Getstatus() { return status; }
        void Setstatus(bool val) { status = val; }

    protected:

    private:
        std::string title;
        std::string description;
        date due_date;
        int priority;
        bool status;
};

#endif // TASK_H
