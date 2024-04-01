#include "RangeRover.h"
RangeRover::RangeRover() : Car("RangeRover", 70, 15, 125, 80, 45) {}

double RangeRover::calculateTime(int circuitLength, Weather weather)
{
    double time;
    double averageSpeed;

    switch (weather)
    {
    case Weather::Rain:
        averageSpeed = avg_speed_rain;
        break;
    case Weather::Sunny:
        averageSpeed = avg_speed_sunny;
        break;
    case Weather::Snow:
        averageSpeed = avg_speed_snow;
        break;
    }

    time = circuitLength / averageSpeed;

    return time;
}

std::string RangeRover::GetName()
{
    return name;
}

bool RangeRover::Finish(double circuit_len)
{
    if (fuel_cap * fuel_cons / 100 > circuit_len) return 1;
    return 0;
}