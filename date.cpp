#include "date.h"

date::date()    // Costruttore default
{
    day = 0;
    month = 0;
    year = 0;
}

date::date(int Day, int Month, int Year)    // Costruttore sovraccaricato
{
    day = Day;
    month = Month;
    year = Year;
}

// Metodo che restituisce true se la data è passata
bool date::is_expired(){

    date current_date;

    // Inizializza la data attuale
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    current_date.Setday(now->tm_mday);
    current_date.Setmonth(now->tm_mon +1);
    current_date.Setyear(now->tm_year + 1900);

    // Confronta la data voluta con la data attuale, ritorna true se la prima è minore,
    // Secondo l'ordinamento definito nel file header
    return *this<current_date;
}
