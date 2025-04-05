#include <iostream>
#include <string>

#include <vector>
#include <algorithm>
#include <map>

#include <fstream>

#include "date.h"
#include "task.h"

using std::cout, std::cin, std::string;

string int_to_priority_name(int prio_num){
    switch (prio_num){
    case 0: return "not important"; break;
    case 1: return "very low"; break;
    case 2: return "low"; break;
    case 3: return "medium"; break;
    case 4: return "high"; break;
    case 5: return "very high"; break;
    default: return "unknown"; break;
    }
}

int priority_name_to_int(string prio_str){
    if (prio_str == "not important"){ return 0;
    } else if (prio_str == "very_low"){ return 1;
    } else if (prio_str == "low"){ return 2;
    } else if (prio_str == "medium"){ return 3;
    } else if (prio_str == "high"){ return 4;
    } else if (prio_str == "very high"){ return 5;
    } else { return -1;
    }
}

string int_to_status_name(int status_num){
    switch (status_num){
    case -1: return "expired"; break;
    case 0: return "completed"; break;
    case 1: return "pending"; break;
    default: return "unknown"; break;
    }
}

int status_name_to_int(string status_str){
    if (status_str == "expired"){ return -1;
    } else if (status_str == "completed"){ return 0;
    } else if (status_str == "pending"){ return 2;
    } else { return -1;
    }
}

bool next_line_empty_check(std::ifstream& file, std::streampos curr_pos){
        string line;
        file.seekg(curr_pos);
        std::getline(file, line);
        if (line.empty()){
            file.clear();  // Clear EOF or fail flag if needed
            file.seekg(curr_pos);
            return true;
        }
        else {
            file.clear();  // Clear EOF or fail flag if needed
            file.seekg(curr_pos);
            return false;
        }
}

date string_to_date(string date_str){
    date data;

    int position1 = date_str.find("/");
    data.Setday(std::stoi(date_str.substr(0,position1)));
    date_str.erase(0,position1+1);

    int position2 = date_str.find("/");
    data.Setmonth(std::stoi(date_str.substr(0,position2)));
    date_str.erase(0,position2+1);

    int position3 = date_str.find(" ");
    data.Setyear(std::stoi(date_str.substr(0,position3)));

    return data;
}

void fill_mmaps(std::multimap<int, task>& priority_mmap, std::multimap<int, task>& status_mmap){

    std::ifstream input_file("todolist.txt");

    if (input_file.is_open()) {

        std::streampos curr_pos = input_file.tellg();
        string line;
        string temp_string;

        while(next_line_empty_check(input_file, curr_pos) == false){

            task tsk;

            std::getline(input_file, temp_string);

            std::getline(input_file, temp_string);
            tsk.Settitle(temp_string);

            std::getline(input_file, temp_string);
            tsk.Setdescription(temp_string);

            std::getline(input_file, temp_string);
            temp_string.erase(0, temp_string.find(": ")+2);
            tsk.Setpriority(priority_name_to_int(temp_string));

            std::getline(input_file, temp_string);
            temp_string.erase(0, temp_string.find(": ")+2);
            tsk.Setdue_date(string_to_date(temp_string));

            std::getline(input_file, temp_string);
            temp_string.erase(0, temp_string.find(": ")+2);
            tsk.Setstatus(status_name_to_int(temp_string));

            std::getline(input_file, temp_string);

            curr_pos = input_file.tellg();

            priority_mmap.insert({tsk.Getpriority(), tsk});
            status_mmap.insert({tsk.Getstatus(), tsk});
        }
        input_file.close();
    }
    else {
        std::cerr << "Unable to open file\n";
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
    string status_name = int_to_status_name(ts.Getstatus());
    out_stream << "------------------------------ \n"<< ts.Gettitle() << "\n" <<
    ts.Getdescription() << "\n" << "Priority: "<<prio_name<<"\n"<< "Due date: "<<task_date<<
    "\nStatus: "<<status_name<<"\n------------------------------ \n";
    return out_stream;
}


int main()
{

    /*
    date new_date2;
    cout<<new_date2.Getday()<<"\n";
    date new_date = date(12,3,2025);
    cout<<new_date.Getday()<<"\n";
    cout<<new_date<<"\n";

    task new_task;
    cout<<new_task.Gettitle()<<"\n";
    date date3 = new_task.Getdue_date();
    cout<<date3<<"\n";

    task new_task2 = task("First new task", date(12,3,2000), 2, 0);
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

    std::map<int , task> status_map = {
    {new_task.Getstatus(), new_task},
    {new_task2.Getstatus(), new_task2}
    };
    */

    std::multimap<int, task> priority_mmap;
    std::multimap<int, task> status_mmap;

    fill_mmaps(priority_mmap, status_mmap);

    for ( auto& pair : priority_mmap){
        cout<<pair.second;
    }











    return 0;
}
