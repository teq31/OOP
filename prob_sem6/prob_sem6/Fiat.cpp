#include "Fiat.h"
Fiat::Fiat() : Car("Fiat", 45, 8, 130, 75, 30) {}

double Fiat::calculateTime(int circuitLength, Weather weather)
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

std::string Fiat::GetName()
{
    return name;
}

bool Fiat::Finish(double circuit_len)
{
    if (fuel_cap * fuel_cons > circuit_len) return 1;
    return 0;
}