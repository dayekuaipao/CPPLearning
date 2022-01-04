struct DayInfo
{
    enum Day
    {
        SUNDAY,MONDAY,TUESDAY,WEDNESDAY,THURSDAY,FRIDAY,SATURDAY
    };
    enum Weather
    {
        SUNNY,RAINY,CLOUDY,FROGGY
    };
    Day day;
    Weather weather;
};
bool canTravel(DayInfo dayinfo);