#include "date.h"

date::date()
{
    day = 0;
    month = 0;
    year = 0;
}

date::date(int Day, int Month, int Year)
{
    day = Day;
    month = Month;
    year = Year;
}

bool date::is_expired(){

    date current_date;

    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    current_date.Setday(now->tm_mday);
    current_date.Setmonth(now->tm_mon +1);
    current_date.Setyear(now->tm_year + 1900);

    return *this<current_date;
}
