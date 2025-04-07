#ifndef DATE_H
#define DATE_H

#include<ctime>

class date
{
    public:
        date();     // Costruttore default
        date(int, int, int);    // Costruttore sovraccaricato

        // Getters e setters
        int Getday() const { return day; }
        void Setday(int val) { day = val; }
        int Getmonth() const { return month; }
        void Setmonth(int val) { month = val; }
        int Getyear() const { return year; }
        void Setyear(int val) { year = val; }

        // Sovraccarica l'operatore di confronto < per confronti più veloci tra date
        bool operator<( const date& other_date) const {
            if (Getyear() != other_date.Getyear()){
                return Getyear()<other_date.Getyear();
            } else if (Getmonth() != other_date.Getmonth()){
                return Getmonth()<other_date.Getmonth();
            } else {
                return Getday()<other_date.Getday();
            }
        }

        // Sovraccarica l'operatore di confronto > per confronti più veloci tra date.
        // Nota: serve definire questo a parte per confronti automatici della mappa date_mmap
        bool operator>(const date& other_date) const {
            return other_date < *this;
        }

        // Metodo che restituisce true se la data è passata
        bool is_expired();

    protected:

    private:
        int day;
        int month;
        int year;
};

#endif // DATE_H
