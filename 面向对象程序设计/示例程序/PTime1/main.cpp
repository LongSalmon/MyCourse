#include <iostream>

#include "mytime"

using namespace nsname;
using namespace std;

int main()
{
    CTime c1;
    c1.SetTime(24,20,32);
    c1.ShowTime();
    cout << endl;
    c1.addMin(12);
    c1.ShowTime();
    cout << endl;
    return 0;
}
