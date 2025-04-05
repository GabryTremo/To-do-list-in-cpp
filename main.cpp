#include <iostream>
#include <string>

#include "date.h"
#include "task.h"

using std::cout, std::cin, std::string;

// Spiegazione: sovraccarica l'operatore << in modo da far stampare date nel modo voluto.
// La corrente di output out_stream è passata per referenza perchè vogliamo cambiarla
// senza copiarla.
// La data dt viene passata per referenza perchè non vogliamo copiare una classe. Inoltre,
// è const perchè non vogliamo cambiarla.
// Infine, ritorna una referenza, ad esempio per concatenare date.
std::ostream& operator<<(std::ostream& out_stream, date& dt) {
    out_stream << dt.Getday() << "/" << dt.Getmonth() << "/" << dt.Getyear();
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



    return 0;
}
