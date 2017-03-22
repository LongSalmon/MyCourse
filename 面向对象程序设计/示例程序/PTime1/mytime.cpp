#include <iostream>
#include <ctime>
#include <cmath>

#include "mytime.h"

using namespace nsname;

HoursSystem CTime::System = HS24;
std::string CTime::city = "Wuhan";

/*
CTime::CTime()
{
    hour = 0;
    minute = 0;
    second = 0;
}
*/

CTime::CTime(int h, int m, int s): hour(h), minute(m), second(s)
{
    zone = new std::string("Beijing");
}

CTime::CTime(const std::string &atime)
{
    int * v[3]= {&hour, &minute, &second};
    int p = 0;
    hour = minute = second = 0;
    for(size_t i = 0; i < atime.size(); i++) {
        if(atime[i] == ':') {
            p++;
            continue;
        }
        *(v[p]) = *(v[p]) * 10 + int(atime[i] - '0');
    }
    zone = new std::string("Beijing");
}

CTime::CTime(time_t now)
{
    struct tm * pt = localtime(&now);
    hour = pt->tm_hour;
    minute = pt->tm_min;
    second = pt->tm_sec;
    zone = new std::string("Beijing");
}


CTime::CTime(const CTime& x)
{
    hour = x.hour;
    minute = x.minute;
    second = x.second;
    zone = new std::string(*x.zone);
}

CTime::~CTime()
{
    delete zone;
}

int CTime::getHour() const
{
    return hour;
}

void CTime::setHour(int h)
{
    if((h >= 0) && (h < 24)) hour = h;
}

int CTime::getMin() const
{
    return minute;
}

int CTime::getSec() const
{
    return second;
}

void CTime::setMin(int m)
{
    if((m >= 0) && (m < 60)) minute = m;
}

void CTime::setSec(int s)
{
    if((s >= 0) && (s < 60)) second = s;
}

void CTime::SetTime(int h, int m, int s)
{
    hour = minute = second = 0;
    setHour(h);
    setMin(m);
    setSec(s);
}

void CTime::ShowTime()
{
    int hh = hour;
    std::string postfix("");
    if(HS12 == System) {
        postfix = "AM";
        if (12 < hh) {
            hh -= 12;
            postfix = "PM";
        }
    }
    std::cout << *zone << "(" << hh << ":" << minute
              << ":" << second << postfix << "," << city <<")";
}

void CTime::addHour(int h)
{
    hour += h;
    hour %= 24;
}

void CTime::addMin(int m)
{
    minute += m;
    addHour(minute / 60);
    minute %= 60;
}

void CTime::addSec(int s)
{
    second += s;
    addMin(second / 60);
    second %= 60;
}

void CTime::showCity()
{
    std::cout << city;
}

void CTime::setHoursSystem(HoursSystem hs)
{
    System = hs;
}

CTime operator +(const CTime& t, int s)
{
    CTime r(t);
    r.addSec(s);
    return r;
}

CTime& operator -=(CTime &x, int s)
{
    int h, m;
    s = x.getSec() - s;
    m = abs(s / 60);
    s = s % 60;
    if(0 > s) {
        m++;
        s += 60;
    }
    m = x.getMin() - m;
    h = abs(m / 60);
    m = m % 60;
    if(0 > m) {
        h++;
        m += 60;
    }
    h = (x.getHour() - h) % 24;
    if(0 > h) {
        h += 24;
    }
    x.setHour(h);
    x.setMin(m);
    x.setSec(s);
    return x;
}

int operator -(const CTime &x, const CTime &y)
{
    int a = x.getHour() * 3600 + x.getMin() * 60 + x.getSec();
    int b = y.getHour() * 3600 + y.getMin() * 60 + y.getSec();
    return abs(a - b);
}

namespace nsname {
CTime operator -(const CTime& x, int s)
{
    CTime r(x);
    r -= s;
    return r;
}

CTime& operator +=(CTime &x, int s)
{
    int h, m;
    x.second += s;
    m = x.second / 60;
    x.second %= 60;
    if(0 > x.second) {
        m--;
        x.second += 60;
    }
    x.minute += m;
    h = x.minute / 60;
    x.minute %= 60;
    if(0 > x.minute) {
        h--;
        x.minute += 60;
    }
    x.hour = (x.hour - h) % 24;
    if(0 > x.hour) {
        x.hour += 24;
    }
    return x;
}
} //end of namespace nsname
