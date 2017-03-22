#include <iostream>

#include "mytime.h"

using namespace nsname;
using namespace std;

int main()
{
    CTime::showCity();
    cout << endl;
    CTime c1("13:24:32");
    CTime c2("10:32:32");
    cout << "c1 =";
    c1.ShowTime();
    cout << "\t c2 =";
    c2.ShowTime();
    cout << endl;

    CTime::city = "Shanghai";
    cout << "c1 =";
    c1.ShowTime();
    cout << "\t c2 =";
    c2.ShowTime();
    cout << endl;

    CTime::setHoursSystem(HS24);
    cout << "c1 =";
    c1.ShowTime();
    cout << "\t c2 =";
    c2.ShowTime();
    cout << endl;

    c1.setHoursSystem();
    cout << "c1 =";
    c1.ShowTime();
    cout << "\t c2 =";
    c2.ShowTime();
    cout << endl;

    c2.city = "changsa";
    cout << "c1 =";
    c1.ShowTime();
    cout << "\t c2 =";
    c2.ShowTime();
    cout << endl;

    CTime c3(c1 + 20);
    c3.ShowTime();
    cout << endl;

    (c3 + 20).ShowTime();
    cout << "\t c3=";
    c3.ShowTime();
    cout << endl;
    (c3 - 380).ShowTime();
    cout << "\t c3=";
    c3.ShowTime();
    cout << endl;
    c3 -= 500;
    c3.ShowTime();
    cout << endl;
    c3 += 500;
    c3.ShowTime();
    cout << endl;

    cout << "c3 - c1 =" << c3 - c1 << endl;
    return 0;
}
