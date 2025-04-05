#include "task.h"
#include "date.h"

date Default_date = date();

task::task()
{
    title = "Task";
    description = " ";
    due_date = Default_date;
    priority = 0;
    status = true;

}

task::task(std::string Title, date Due_date, int Priority, bool Status)
{
    title = Title;
    description = " ";
    due_date = Due_date;
    priority = Priority;
    status = Status;
}

task::task(std::string Title, std::string Description, date Due_date, int Priority, bool Status)
{
    title = Title;
    description = Description;
    due_date = Due_date;
    priority = Priority;
    status = Status;
}
