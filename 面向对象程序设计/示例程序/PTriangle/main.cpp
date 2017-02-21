#include <iostream>

using namespace std;

int main()
{
    int j, k;
    for(int i = 0; i < 11; i++) {
        k = 21 - (i * 2 + 1) / 2;
        for(j = 0; j < k; j++) {
            cout << " ";
        }
        for(j = 0; j < i * 2 + 1; j++) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}
