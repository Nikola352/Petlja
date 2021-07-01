#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, k;
    cin >> a >> b >> k;

    bool moze = false;

    if((a + k%12) % 12 == b){
        cout << "napred\n";
        moze = true;
    }

    if((a - k%12 + 12) % 12 == b){
        cout << "nazad\n";
        moze = true;
    }

    if(!moze)
        cout << "ne moze\n";

    return 0;
}