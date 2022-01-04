#include "dayinfo.hpp"
bool canTravel(DayInfo dayinfo)
{
    if((dayinfo.day==DayInfo::SUNDAY||dayinfo.day==DayInfo::SATURDAY)
    &&(dayinfo.weather==DayInfo::SUNNY)||(dayinfo.weather==DayInfo::CLOUDY))
        return true;
    return false;
}