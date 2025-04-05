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
