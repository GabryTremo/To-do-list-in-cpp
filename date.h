#ifndef DATE_H
#define DATE_H


class date
{
    public:
        date();     // Costruttore default
        date(int, int, int);    //Costruttore regolare

        int Getday() { return day; }
        void Setday(int val) { day = val; }
        int Getmonth() { return month; }
        void Setmonth(int val) { month = val; }
        int Getyear() { return year; }
        void Setyear(int val) { year = val; }

    protected:

    private:
        int day;
        int month;
        int year;
};

#endif // DATE_H
