#include "task_manipulation.h"
#include "date.h"
#include "task.h"
#include "conversions.h"
#include "order_changes.h"
#include "operator_overloads.h"

#include <iostream>
#include <string>

#include <algorithm>
#include <map>

#include <fstream>

#include <limits>

using std::cout, std::cin, std::string;

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





void fill_mmaps(std::multimap<int, task, std::greater<int>>& priority_mmap, std::multimap<int, task, std::greater<int>>& status_mmap,
                std::map<string, task>& title_map, std::multimap<date, task, std::greater<date>>& date_mmap){

    priority_mmap.clear();
    status_mmap.clear();
    title_map.clear();
    date_mmap.clear();

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
            title_map.insert({tsk.Gettitle(), tsk});
            date_mmap.insert({tsk.Getdue_date(), tsk});

        }
        input_file.close();
    }
    else {
        std::cerr << "Unable to open file\n";
    }

}









void add_task(std::multimap<int, task, std::greater<int>>& priority_mmap, std::multimap<int, task, std::greater<int>>& status_mmap,
              std::map<string, task>& title_map, std::multimap<date, task, std::greater<date>>& date_mmap){
    task ts;
    date dt;
    string input_line;
    int input_num;

    cout<<"Insert the task title: \n";
    std::getline(cin, input_line);
    ts.Settitle(input_line);

    cout<<"Insert the task description, or press 0 for no description: \n";
    std::getline(cin, input_line);
    if (input_line != "0"){
        ts.Setdescription(input_line);
    }

    cout<<"Insert the task priority, from 0 to 5: \n";
    cin>>input_num;
    ts.Setpriority(input_num);

    cout<<"Insert the due date, in the format dd/mm/yyyy (insert the 3 numbers separately): \n";
    cin>>input_num;
    dt.Setday(input_num);
    cin>>input_num;
    dt.Setmonth(input_num);
    cin>>input_num;
    dt.Setyear(input_num);
    ts.Setdue_date(dt);

    if (dt.is_expired()==true){
        ts.Setstatus(-1);
    } else {
        ts.Setstatus(1);
    }

    priority_mmap.insert({ts.Getpriority(), ts});
    status_mmap.insert({ts.Getstatus(), ts});
    title_map.insert({ts.Gettitle(), ts});
    date_mmap.insert({ts.Getdue_date(), ts});

    order_by_priority(priority_mmap);
    cout<<"Task "<<ts.Gettitle()<<" has been added.\n";

}

void delete_task(std::multimap<int, task, std::greater<int>>& priority_mmap, std::multimap<int, task, std::greater<int>>& status_mmap,
                 std::map<string, task>& title_map, std::multimap<date, task, std::greater<date>>& date_mmap){

    string input_title;

    cout<<"Insert the title of the task you want to delete: \n";
    std::getline(cin, input_title);

    if (title_map.count(input_title)==1){
        title_map.erase(input_title);
        cout<<"Task "<<input_title<<" has been deleted.\n";
    } else {
        cout<<"There is no task with that title... \n";
    }

    order_by_title(title_map);

    fill_mmaps(priority_mmap, status_mmap, title_map, date_mmap);

    order_by_priority(priority_mmap);

}

void edit_status(std::multimap<int, task, std::greater<int>>& priority_mmap, std::multimap<int, task, std::greater<int>>& status_mmap,
                 std::map<string, task>& title_map, std::multimap<date, task, std::greater<date>>& date_mmap){

     string input_title;
     cout<<"Insert the title of the task of which you want to change the status (from pending to completed or vice versa): \n";
     getline(cin, input_title);
     auto iter = title_map.find(input_title);

     if (iter != title_map.end()){
        switch (iter->second.Getstatus()){
            case 1: iter->second.Setstatus(0);
                    cout<<"Task "<<input_title<<" has been marked as completed.\n";
                    break;

            case 0: iter->second.Setstatus(1);
                    cout<<"Task "<<input_title<<" has been marked as pending.\n";
                    break;

            case -1: cout<<"The task is expired...\n"; break;
            default: iter->second.Setstatus(1); break;
        }

        order_by_title(title_map);
        fill_mmaps(priority_mmap, status_mmap, title_map, date_mmap);
        order_by_priority(priority_mmap);


    } else {
        cout<<"There is no task with that title... \n";
    }
}

void update_expired(std::multimap<int, task, std::greater<int>>& priority_mmap, std::multimap<int, task, std::greater<int>>& status_mmap,
                    std::map<string, task>& title_map, std::multimap<date, task, std::greater<date>>& date_mmap){

    int expired_count = 0;

    for ( auto& coppia : title_map ){
            if (coppia.second.is_expired() == true && coppia.second.Getstatus() != -1){
                coppia.second.Setstatus(-1);
                expired_count++;
            }
        }

    if (expired_count != 0){
        order_by_title(title_map);
        fill_mmaps(priority_mmap, status_mmap, title_map, date_mmap);
        order_by_priority(priority_mmap);
        cout<<"Some tasks have expired...\nThe list has been ordered by priority.\n";
    }


}

void delete_expired(std::multimap<int, task, std::greater<int>>& priority_mmap, std::multimap<int, task, std::greater<int>>& status_mmap,
                    std::map<string, task>& title_map, std::multimap<date, task, std::greater<date>>& date_mmap){

    int expired_count = 0;

    for (auto iter = title_map.begin(); iter != title_map.end();){
            if (iter->second.Getstatus() == -1){
                cout<<"Task "<<iter->second.Gettitle()<<" has been deleted.\n";
                iter = title_map.erase(iter);
                expired_count++;
            } else {
                iter++;
            }

        }

    if (expired_count == 0){
        cout<<"There were no expired tasks...\n";
    } else{
        order_by_title(title_map);
        fill_mmaps(priority_mmap, status_mmap, title_map, date_mmap);
        order_by_priority(priority_mmap);
        cout<<"The list has been ordered by priority.\n";
    }


}

