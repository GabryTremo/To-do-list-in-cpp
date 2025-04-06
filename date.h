#ifndef DATE_H
#define DATE_H

#include<ctime>




class date
{
    public:
        date();     // Costruttore default
        date(int, int, int);    //Costruttore regolare

        int Getday() const { return day; }
        void Setday(int val) { day = val; }
        int Getmonth() const { return month; }
        void Setmonth(int val) { month = val; }
        int Getyear() const { return year; }
        void Setyear(int val) { year = val; }

        bool operator<( const date& other_date) const {
            if (Getyear() != other_date.Getyear()){
                return Getyear()<other_date.Getyear();
            } else if (Getmonth() != other_date.Getmonth()){
                return Getmonth()<other_date.Getmonth();
            } else {
                return Getday()<other_date.Getday();
            }
        }

        bool operator>(const date& other_date) const {
            return other_date < *this;
        }

        bool is_expired(){

            date current_date;

            std::time_t t = std::time(0);   // get time now
            std::tm* now = std::localtime(&t);
            current_date.Setday(now->tm_mday);
            current_date.Setmonth(now->tm_mon +1);
            current_date.Setyear(now->tm_year + 1900);

            return *this<current_date;
        }

    protected:

    private:
        int day;
        int month;
        int year;
};

#endif // DATE_H
