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

// Funzione che restituisce true se la riga successiva a quella attuale (passata in input) del file passato
// in input è vuota, e false altrimenti.
bool next_line_empty_check(std::ifstream& file, std::streampos curr_pos){

        string line;
        file.seekg(curr_pos);       // Posiziona il puntatore get (che legge il file con getline) nella posizione
                                    // specificata in input

        std::getline(file, line);   // line ora contiene la riga successiva a quella puntata prima
        if (line.empty()){
            file.clear();  // Cancella la flag di fine file o di errore (non sono sicuro sia necessario)
            file.seekg(curr_pos);   // Torna alla linea precedente, in modo che le altre funzioni non siano traslate di
                                    // una riga in avanti.
            return true;
        }
        else {
            file.clear();  // Cancella la flag di fine file o di errore (non sono sicuro sia necessario)
            file.seekg(curr_pos);   // Torna alla linea precedente, in modo che le altre funzioni non siano traslate di
                                    // una riga in avanti.
            return false;
        }
}

// Riempie le 4 mappe a partire dal file .txt
void fill_mmaps(std::multimap<int, task, std::greater<int>>& priority_mmap, std::multimap<int, task, std::greater<int>>& status_mmap,
                std::map<string, task>& title_map, std::multimap<date, task, std::greater<date>>& date_mmap){

    // Svuota le mappe. Se è la prima chiamata chiaramente non serve a nulla, ma è per
    // le chiamate successive, in cui l'aggiornamento viene fatto riempiendo da zero le mappe.
    priority_mmap.clear();
    status_mmap.clear();
    title_map.clear();
    date_mmap.clear();

    std::ifstream input_file("todolist.txt");

    if (input_file.is_open()) {

        std::streampos curr_pos = input_file.tellg();   // Segna la posizione attuale per passarla al check next_empty_line_check
        string line;
        string temp_string;     // Per salvare temporaneamente le righe ottenute da getline

        // Cicla sul numero di task nel file .txt
        while(next_line_empty_check(input_file, curr_pos) == false){

            task tsk;   // Dichiara il nuovo task

            std::getline(input_file, temp_string);  // Scarta la prima riga (contiene -----------)

            // Aggiunge ogni riga consecutiva del file alla variabile corrispondente di task.
            // Titolo e descrizione partono subito, gli altri hanno una scritta prima (tipo "Priority: "),
            // che va ignorata
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

            std::getline(input_file, temp_string);  // Scarta l'ultima riga (contiene -----------)

            // Aggiunge il task alle mappe
            priority_mmap.insert({tsk.Getpriority(), tsk});
            status_mmap.insert({tsk.Getstatus(), tsk});
            title_map.insert({tsk.Gettitle(), tsk});
            date_mmap.insert({tsk.Getdue_date(), tsk});

            curr_pos = input_file.tellg();  // Aggiorna la posizione attuale per passarla al check

        }
        input_file.close();
    }
    else {
        std::cerr << "Unable to open file\n";
    }

}

// Funzione che aggiunge un task, specificato dall'utente, alle varie mappe e al file .txt
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

    // Lo status è inizializzato a 1 ("pending"), a meno che la data sia già passata,
    // nel qual caso è inizializzato a -1 ("expired")
    if (dt.is_expired()==true){
        ts.Setstatus(-1);
    } else {
        ts.Setstatus(1);
    }

    // Aggiorna le mappe
    priority_mmap.insert({ts.Getpriority(), ts});
    status_mmap.insert({ts.Getstatus(), ts});
    title_map.insert({ts.Gettitle(), ts});
    date_mmap.insert({ts.Getdue_date(), ts});

    // Come già evidenziato in precedenza, per aggiornare il file .txt in tempo reale, per come ho
    // definito le cose, è necessario scegliere un ordine arbitrario in cui stamparle nel file da zero.
    // In generale ho scelto l'ordine per priorità decrescente.
    order_by_priority(priority_mmap);

    cout<<"Task "<<ts.Gettitle()<<" has been added.\n";

}

// Funzione che rimuove un task, specificato dall'utente, dalle varie mappe e dal file .txt
void delete_task(std::multimap<int, task, std::greater<int>>& priority_mmap, std::multimap<int, task, std::greater<int>>& status_mmap,
                 std::map<string, task>& title_map, std::multimap<date, task, std::greater<date>>& date_mmap){

    string input_title;

    cout<<"Insert the title of the task you want to delete: \n";
    std::getline(cin, input_title);

    // Il task viene cercato in base al titolo, usato come chiave nella mappa title_map
    if (title_map.count(input_title)==1){
        title_map.erase(input_title);
        cout<<"Task "<<input_title<<" has been deleted.\n";
    } else {
        cout<<"There is no task with that title... \n";
    }

    // Per aggiornare il file e le altre mappe senza codice troppo lungo, stampo nel file .txt la
    // nuova lista con il task rimosso, e dopo riempio le altre mappe a partire dal file. Infine, riordino
    // per priorità decrescente, scelta come ordine di default dopo ogni operazione che non sia ordinamento.
    order_by_title(title_map);
    fill_mmaps(priority_mmap, status_mmap, title_map, date_mmap);
    order_by_priority(priority_mmap);

}

// Funzione che cambia lo status (da "pending" a "completed" o viceversa) di un task selezionato dall'utente,
// e poi aggiorna le mappe e il file .txt
void edit_status(std::multimap<int, task, std::greater<int>>& priority_mmap, std::multimap<int, task, std::greater<int>>& status_mmap,
                 std::map<string, task>& title_map, std::multimap<date, task, std::greater<date>>& date_mmap){

     string input_title;
     cout<<"Insert the title of the task of which you want to change the status (from pending to completed or vice versa): \n";
     getline(cin, input_title);
     auto iter = title_map.find(input_title);

     if (iter != title_map.end()){      // Se il file col titolo scelto esiste

        switch (iter->second.Getstatus()){      // Switch sul valore della variabile status del task trovato da find
            case 1: iter->second.Setstatus(0);
                    cout<<"Task "<<input_title<<" has been marked as completed.\n";
                    break;

            case 0: iter->second.Setstatus(1);
                    cout<<"Task "<<input_title<<" has been marked as pending.\n";
                    break;

            case -1: cout<<"The task is expired...\n"; break;
            default: iter->second.Setstatus(1); break;
        }

        // Per aggiornare il file e le altre mappe senza codice troppo lungo, stampo nel file .txt la
        // nuova lista con il task modificato, e dopo riempio le altre mappe a partire dal file. Infine, riordino
        // per priorità decrescente, scelta come ordine di default dopo ogni operazione che non sia ordinamento.
        order_by_title(title_map);
        fill_mmaps(priority_mmap, status_mmap, title_map, date_mmap);
        order_by_priority(priority_mmap);

    } else {
        cout<<"There is no task with that title... \n";
    }
}

// Funzione per segnare automaticamente come scaduti i task che hanno data precedente ad oggi.
void update_expired(std::multimap<int, task, std::greater<int>>& priority_mmap, std::multimap<int, task, std::greater<int>>& status_mmap,
                    std::map<string, task>& title_map, std::multimap<date, task, std::greater<date>>& date_mmap){

    int expired_count = 0;  // Contatore per il numero di task scaduti dall'ultima volta (in realtà uso solo se è 0 o non 0)

    for ( auto& coppia : title_map ){
            if (coppia.second.is_expired() == true && coppia.second.Getstatus() != -1){
                // Aggiorno solo quelli che sono scaduti ma non erano segnati come tali nel file
                coppia.second.Setstatus(-1);
                expired_count++;
            }
        }

    if (expired_count != 0){
        // Se è stato aggiornato almeno un file, aggiorna tutto nel modo spiegato sopra
        order_by_title(title_map);
        fill_mmaps(priority_mmap, status_mmap, title_map, date_mmap);
        order_by_priority(priority_mmap);
        cout<<"Some tasks have expired...\nThe list has been ordered by priority.\n";
    }


}

// Funzione per rimuovere automaticamente i task segnati come scaduti
void delete_expired(std::multimap<int, task, std::greater<int>>& priority_mmap, std::multimap<int, task, std::greater<int>>& status_mmap,
                    std::map<string, task>& title_map, std::multimap<date, task, std::greater<date>>& date_mmap){

    int expired_count = 0;  // Contatore per il numero di task scaduti (in realtà uso solo se è 0 o non 0)

    // Nota: non si può fare ciclo for di tipo range, perchè gli iteratori vengono mandati un po' in
    // confusione dalla cancellazione dei task all'interno del ciclo. Viene fatto un ciclo con modifica manuale dell'iteratore
    for (auto iter = title_map.begin(); iter != title_map.end();){
            // Se il task a cui punta l'iteratore è scaduto, lo elimina e mette il puntatore alla prossima
            // posizione disponibile (fatto in automatico da title_map.erase(iter) ), altrimenti porta manualmente
            // l'iteratore alla posizione successiva della mappa.
            if (iter->second.Getstatus() == -1){
                // Nota: va segnato il nome prima di cancellare il task
                cout<<"Task "<<iter->second.Gettitle()<<" has been deleted.\n";
                iter = title_map.erase(iter);
                expired_count++;
            } else {
                iter++;
            }
        }

    // Se almeno un task era scaduto ed è stato quindi rimosso, aggiorna tutto come spiegato sopra
    if (expired_count == 0){
        cout<<"There were no expired tasks...\n";
    } else{
        order_by_title(title_map);
        fill_mmaps(priority_mmap, status_mmap, title_map, date_mmap);
        order_by_priority(priority_mmap);
        cout<<"The list has been ordered by priority.\n";
    }
}

