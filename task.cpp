#include "task.h"
#include "date.h"

#include <iostream>
#include <string>

using std::cout, std::cin, std::string;

date Default_date = date();     // Per il costruttore default sarà usata la data default 00/00/0000

task::task()    // Costruttore default
{
    title = "Task";
    description = " ";
    due_date = Default_date;
    priority = 0;
    status = 1;

}

task::task(string Title, date Due_date, int Priority, int Status)   // Costruttore sovraccaricato, senza descrizione
{
    title = Title;
    description = " ";
    due_date = Due_date;
    priority = Priority;
    status = Status;
}

task::task(string Title, string Description, date Due_date, int Priority, int Status)   // Costruttore sovraccaricato, con descrizione
{
    title = Title;
    description = Description;
    due_date = Due_date;
    priority = Priority;
    status = Status;
}
