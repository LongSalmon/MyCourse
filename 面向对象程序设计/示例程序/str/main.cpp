#include <iostream>
#include <string>

using namespace std;

namespace zhongsan {

void swap(string* s1, string* s2);
void swap1(string s1, string s2);
void swap2(string &s1, string &s2);
string strcat(string s1, string s2);
string* strcat1(string s1, string s2);

}

namespace zs = zhongsan;

int main()
{
    string *s1;
    s1 = new string("this is s string.");
    cout << *s1 << endl << endl;
    delete s1;

    string s2, s3;
    s2 = "string 2";
    s3 = "string 3";
    zs::swap1(s2, s3);
    cout << "s2:" << s2 << endl;
    cout << "s3:" << s3 << endl;
    cout << endl;

    zs::swap(&s2, &s3);
    cout << "s2:" << s2 << endl;
    cout << "s3:" << s3 << endl;

    int x = 100;
    int &rx = x;
    cout << rx << endl;

    zs::swap2(s2, s3);
    cout << "s2:" << s2 << endl;
    cout << "s3:" << s3 << endl;

    return 0;
}

void zs::swap(string* s1, string* s2)
{
    string tmp = *s1;
    *s1 = *s2;
    *s2 = tmp;
}

void zs::swap1(string s1, string s2)
{
    string tmp = s1;
    s1 = s2;
    s2 = tmp;
    cout << "F s2:" << s1 << endl;
    cout << "F s3:" << s2 << endl;
}

string zs::strcat(string s1, string s2)
{
    return s1 + s2;
}

string* zs::strcat1(string s1, string s2)
{
    string* s = new string(s1 + s2);
    return s;
}

void zs::swap2(string &s1, string &s2)
{
    string s = s1;
    s1 = s2;
    s2 = s;
}
