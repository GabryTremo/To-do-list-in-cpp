#include "operator_overloads.h"
#include "conversions.h"
#include "date.h"
#include "task.h"

#include <iostream>
#include <string>

#include <fstream>

using std::cout, std::cin, std::string;

// Sovraccarica l'operatore << in modo da far stampare date nel modo voluto.
// La corrente di output out_stream è passata per referenza perchè vogliamo cambiarla
// senza copiarla.
// La data dt viene passata per referenza perchè non vogliamo copiare la classe.
// Infine, ritorna una referenza, ad esempio per concatenare date.
std::ostream& operator<<(std::ostream& out_stream, date& dt) {

    out_stream << dt.Getday() << "/" << dt.Getmonth() << "/" << dt.Getyear();
    return out_stream;

}

// Stessa cosa ma con l'operatore << per task anzichè date
std::ostream& operator<<(std::ostream& out_stream, task& ts) {

    date task_date = ts.Getdue_date();
    string prio_name = int_to_priority_name(ts.Getpriority());
    string status_name = int_to_status_name(ts.Getstatus());

    out_stream << "------------------------------ \n"<< ts.Gettitle() << "\n" <<
    ts.Getdescription() << "\n" << "Priority: "<<prio_name<<"\n"<< "Due date: "<<task_date<<
    "\nStatus: "<<status_name<<"\n------------------------------ \n";
    return out_stream;

}
