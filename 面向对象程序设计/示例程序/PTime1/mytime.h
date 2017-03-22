#ifndef _TIME__
#define _TIME__

#include <string>
#include <ctime>

namespace nsname {

typedef enum {HS12, HS24} HoursSystem;

class CTime
{
private:
    int hour;
    int minute;
    int second;
    static HoursSystem System; //仅对象间可共享的成员

public:
//    CTime();
    CTime(int, int, int);
    CTime(const std::string &atime);
    CTime(time_t now = time(NULL));
    CTime(const CTime& x);

    ~CTime();

    std::string * zone;
    static std::string city; //对象间共享，可通过类名直接访问的成员

    int getHour() const; //取值函数
    void setHour(int h); //设值函数
    int getMin() const; //取值函数
    void setMin(int m); //设值函数
    int getSec() const; //取值函数
    void setSec(int s); //设值函数

    void SetTime(int h, int m, int s);
    void ShowTime();
    void addHour(int);
    void addMin(int);
    void addSec(int);

    static void showCity();
    static void setHoursSystem(HoursSystem hs=HS12);

    friend CTime& operator +=(CTime& x, int s);
};

CTime operator - (const CTime& x, int s);

} // end of namespace nsname

nsname::CTime operator + (const nsname::CTime& t, int s);
int operator - (const nsname::CTime& x, const nsname::CTime& y);
nsname::CTime& operator -= (nsname::CTime& x, int s);

#endif // __TIME__
