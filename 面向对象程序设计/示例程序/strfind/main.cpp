#include <iostream>
#include <string>

using namespace std;

int main()
{
    //char s1[20];
    //char s2[10];
    //char s3[30];
    string s1; //string s1, s2;
    string s2;
    cin >> s1; // cin >> s1 >> s2;
    cin >> s2;
    s1 += s2;  // s1 = s1 + s2;
    // s1.append(s2);
    // s1.append("adfasdfasf");
    //strcat(s3, s2);
    cout << s1;
    return 0;
}
