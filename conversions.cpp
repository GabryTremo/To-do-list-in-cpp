#include "conversions.h"
#include "date.h"

#include <iostream>
#include <string>

using std::cout, std::cin, std::string;

// Per convertire il numero da 0 a 5 della priorità nelle stringhe corrispondenti
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

// Viceversa. Non si può fare con switch perche prende solo interi
int priority_name_to_int(string prio_str){
    if (prio_str == "not important"){ return 0;
    } else if (prio_str == "very low"){ return 1;
    } else if (prio_str == "low"){ return 2;
    } else if (prio_str == "medium"){ return 3;
    } else if (prio_str == "high"){ return 4;
    } else if (prio_str == "very high"){ return 5;
    } else { return -1;
    }
}

// Per convertire il numero -1, 0 o 1 della priorità nelle stringhe corrispondenti
string int_to_status_name(int status_num){
    switch (status_num){
    case -1: return "expired"; break;
    case 0: return "completed"; break;
    case 1: return "pending"; break;
    default: return "unknown"; break;
    }
}

// Viceversa. Non si può fare con switch perche prende solo interi
int status_name_to_int(string status_str){
    if (status_str == "expired"){ return -1;
    } else if (status_str == "completed"){ return 0;
    } else if (status_str == "pending"){ return 1;
    } else { return -1;
    }
}

// Per convertire la stinga nella forma dd/mm/yyyy in un oggetto della classe date (quindi 3 interi)
date string_to_date(string date_str){
    date data;

    // Nota: si può cancellare i pezzi della stringa perchè è passata per valore
    int position1 = date_str.find("/");     // Restituisce l'iteratore che punta dove c'è la prima barra /
    data.Setday(std::stoi(date_str.substr(0,position1)));   // Taglia la stringa fino alla prima barra, e la trasforma in int
    date_str.erase(0,position1+1);      // Cancella la parte analizzata della stringa, per poter analizzare allo stesso modo il mese

    int position2 = date_str.find("/");
    data.Setmonth(std::stoi(date_str.substr(0,position2)));
    date_str.erase(0,position2+1);

    int position3 = date_str.find(" ");
    data.Setyear(std::stoi(date_str.substr(0,position3)));

    return data;
}

