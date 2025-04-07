#include "date.h"
#include "task.h"
#include "conversions.h"
#include "order_changes.h"
#include "operator_overloads.h"
#include "task_manipulation.h"

#include <iostream>
#include <string>
#include <algorithm>    // Comandi per manipolare oggetti della STL
#include <map>
#include <fstream>      // Per operazioni con file esterni
#include <ctime>        // Per confrontare con data attuale
#include <limits>       // Usato per correggere input cin

using std::cout, std::cin, std::string;

int main()
{
    // ------------- Dichiarazioni -------------
    int selection;                  // Salva la selezione dell'utente nella prima scelta
    int order_selection;            // Salva la selezione dell'utente nella scelta dell'ordinamento
    bool continue_check = true;     // Per chiudere l'interfaccia quando l'utente seleziona 0

        // Maps o multimaps per salvare i task con possibili chiavi le diverse variabili della
        // classe task, in modo da poter ordinare nei diversi modi.
    std::multimap<int, task, std::greater<int>> priority_mmap;
    std::multimap<int, task, std::greater<int>> status_mmap;
    std::map<string, task> title_map;
    std::multimap<date, task, std::greater<date>> date_mmap;

    // ------------- Inizializzazione e aggiornamento -------------

    fill_mmaps(priority_mmap, status_mmap, title_map, date_mmap);       // Riempie le mappe

    update_expired(priority_mmap, status_mmap, title_map, date_mmap);   // Se dei task sono scaduti dall'ultima volta in cui è stato
                                                                        // usato il programma, li segna come scaduti.

    // ------------- Interfaccia utente -------------

    while(continue_check == true){
        cout<<"What do you want to do?\n1 : Add a task\n2 : Change the status of a task\n3 : Remove a task\n4 : Remove all expired tasks\n";
        cout<<"5 : Order tasks\n0 : Exit\n";
        cin>>selection;

        switch(selection){

            // Il primo comando all'inizio di ogni case serve a pulire l'input buffer. Senza di quello,
            // i vari getline nelle funzioni chiamate prenderebbero come prima riga il /n lasciato da cin.

            // Nota: ogni volta che viene aggiunto, rimosso o modificato un task, per come sono fatte le
            // mappe, è necessario scegliere una mappa specifica per aggiornare il file .txt, e quindi un
            // ordine specifico "di default". Qui è stato scelto l'ordine per priorità come default.

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
                    break;  // Fine case 5

            case 0: continue_check = false; break;
            default: continue;
        }
    }

    return 0;
}
