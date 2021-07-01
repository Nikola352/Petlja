#include <iostream>
using namespace std;

int main()
{
    int s=0, p=1;
    for(int i=0; i<4; i++){
        int x;
        cin >> x;
        s += x;
        s %= 1000;
        p *= x;
        p %= 1000;
    }
    
    cout << s << endl << p << endl;

    return 0;
}