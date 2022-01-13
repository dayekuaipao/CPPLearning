#include"dayinfo.hpp"
#include<iostream>
using namespace std;
int main()
{
    DayInfo dayinfo1,dayinfo2,dayinfo3;
    dayinfo1.day = DayInfo::WEDNESDAY;
    dayinfo1.weather = DayInfo::SUNNY;

    dayinfo2.day = DayInfo::SUNDAY;
    dayinfo2.weather = DayInfo::FOGGY;

    dayinfo3.day = DayInfo::SUNDAY;
    dayinfo3.weather = DayInfo::CLOUDY;

    cout<<"day1: "<<canTravel(dayinfo1)<<" day2: "<<canTravel(dayinfo2)<<" day3: "<<canTravel(dayinfo3)<<endl;
}