#include <iostream>
#include <string>

#include <vector>
#include <algorithm>
#include <map>

#include "date.h"
#include "task.h"

using std::cout, std::cin, std::string;

string int_to_priority_name(int prio_num){
    switch (prio_num){
    case 0: return "not important";
    case 1: return "very low";
    case 2: return "low";
    case 3: return "medium";
    case 4: return "high";
    case 5: return "very high";
    default: return "unknown";
    }
}

// Spiegazione: sovraccarica l'operatore << in modo da far stampare date nel modo voluto.
// La corrente di output out_stream è passata per referenza perchè vogliamo cambiarla
// senza copiarla.
// La data dt viene passata per referenza perchè non vogliamo copiare una classe.
// Infine, ritorna una referenza, ad esempio per concatenare date.
std::ostream& operator<<(std::ostream& out_stream, date& dt) {
    out_stream << dt.Getday() << "/" << dt.Getmonth() << "/" << dt.Getyear();
    return out_stream;
}

std::ostream& operator<<(std::ostream& out_stream, task& ts) {
    date task_date = ts.Getdue_date();
    string prio_name = int_to_priority_name(ts.Getpriority());
    out_stream << "------------------------------ \n"<< ts.Gettitle() << "\n" <<
    ts.Getdescription() << "\n" << "Priority: "<<prio_name<<"\n"<< "Due date: "<<task_date<<"\n------------------------------ \n";
    return out_stream;
}


int main()
{

    date new_date2;
    cout<<new_date2.Getday()<<"\n";
    date new_date = date(12,3,2025);
    cout<<new_date.Getday()<<"\n";
    cout<<new_date<<"\n";

    task new_task;
    cout<<new_task.Gettitle()<<"\n";
    date date3 = new_task.Getdue_date();
    cout<<date3<<"\n";

    task new_task2 = task("First new task", date(12,3,2000), 2, true);
    cout<<new_task2.Gettitle()<<"\n";
    date date4 = new_task2.Getdue_date();
    cout<<date4<<"\n";


    std::map<int , task> priority_map = {
    {new_task.Getpriority(), new_task},
    {new_task2.Getpriority(), new_task2}
    };

    for ( auto& pair : priority_map){
        cout<<pair.second;
    }





/*


    std::map<task , int> priority_map = {
    {new_task, 2},
    {new_task2, 3}
    };

    std::map<task , bool> status_map = {
    {new_task, new_task.Getstatus()},
    {new_task2, new_task2.Getstatus()}
    };
    */







    return 0;
}
