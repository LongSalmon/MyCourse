#include <iostream>

#include "mytime"

using namespace nsname;
using namespace std;

void CTime::SetTime(int h, int m, int s)
{
    hour = h;
    minute = m;
    second = s;
}

void CTime::ShowTime()
{
    cout << hour << ":" << minute << ":" << second;
}

void CTime::addHour(int h)
{
    hour += h;
}

void CTime::addMin(int m)
{
    minute += m;
}

void CTime::addSec(int s)
{
    second += s;
}
