#include <iostream>

#include "mytime"

using namespace nsname;
using namespace std;

int CTime::GetHour()
{
    return hour;
}

int CTime::GetMin()
{
    return minute;
}

int CTime::GetSec()
{
    return second;
}

void CTime::SetHour(int h)
{
    if((h >= 0) && (h < 24)) hour = h;
}

void CTime::SetMin(int m)
{
    if((m >= 0) && (m < 60)) minute = m;
}

void CTime::SetSec(int s)
{
    if((s >= 0) && (s < 60)) second = s;
}

void CTime::SetTime(int h, int m, int s)
{
    hour = minute = second = 0;
    SetHour(h);
    SetMin(m);
    SetSec(s);
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
