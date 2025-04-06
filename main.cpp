#include "date.h"
#include "task.h"
#include "conversions.h"
#include "order_changes.h"
#include "operator_overloads.h"
#include "task_manipulation.h"

#include <iostream>
#include <string>

#include <algorithm>
#include <map>

#include <fstream>

#include <ctime>

#include <limits>

using std::cout, std::cin, std::string;

int main()
{
    int selection;
    int order_selection;
    bool continue_check = true;

    std::multimap<int, task, std::greater<int>> priority_mmap;
    std::multimap<int, task, std::greater<int>> status_mmap;
    std::map<string, task> title_map;
    std::multimap<date, task, std::greater<date>> date_mmap;

    fill_mmaps(priority_mmap, status_mmap, title_map, date_mmap);

    update_expired(priority_mmap, status_mmap, title_map, date_mmap);

    while(continue_check == true){
        cout<<"What do you want to do?\n1 : Add a task\n2 : Change the status of a task\n3 : Remove a task\n4 : Remove all expired tasks\n";
        cout<<"5 : Order tasks\n0 : Exit\n";
        cin>>selection;

        switch(selection){
            case 1: cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    add_task(priority_mmap,status_mmap, title_map, date_mmap);
                    cout<<"The list has been ordered by priority.\n";
                    break;
            case 2: cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    edit_status(priority_mmap,status_mmap, title_map, date_mmap);
                    cout<<"The list has been ordered by priority.\n";
                    break;
            case 3: cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    delete_task(priority_mmap,status_mmap, title_map, date_mmap);
                    cout<<"The list has been ordered by priority.\n";
                    break;
            case 4: cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    delete_expired(priority_mmap,status_mmap, title_map, date_mmap);

                    break;
            case 5: cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout<<"What order would you like?\n1 : By due date\n2 : By priority\n3 : By status\n4 : By title\n0 : Go back\n";
                    cin>>order_selection;

                    switch (order_selection){
                        case 1: cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                order_by_date(date_mmap);
                                cout<<"The list has been ordered by due date.\n";
                                break;
                        case 2: cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                order_by_priority(priority_mmap);
                                cout<<"The list has been ordered by priority.\n";
                                break;
                        case 3: cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                order_by_status(status_mmap);
                                cout<<"The list has been ordered by status.\n";
                                break;
                        case 4: cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        order_by_title(title_map);
                                cout<<"The list has been ordered by title.\n";
                                break;
                        case 0: break;
                        default: break;
                    }
                    break;
            case 0: continue_check = false; break;
            default: break;
        }
    }

    return 0;
}
