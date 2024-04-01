#include "Seat.h"
Seat::Seat() : Car("Seat", 55, 5, 120, 87, 75) {}

double Seat::calculateTime(int circuitLength, Weather weather)
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

std::string Seat::GetName()
{
    return name;
}

bool Seat::Finish(double circuit_len)
{
    if (fuel_cap * fuel_cons > circuit_len) return 1;
    return 0;
}