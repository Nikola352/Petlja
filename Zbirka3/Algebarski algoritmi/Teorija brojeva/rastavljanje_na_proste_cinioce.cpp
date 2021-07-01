#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int br = n;

    while(br % 2 == 0){
        br /= 2;
        cout << 2 << ' ';
    }
    while(br % 3 == 0){
        br /= 3;
        cout << 3 << ' ';
    }

    for(int i=5; i*i<=n; i+=6){
        while(br % i == 0){
            br /= i;
            cout << i << ' ';
        }
        while(br % (i+2) == 0){
            br /= i+2;
            cout << i+2 << ' ';
        }
    }

    if(br > 1) cout << br;

    return 0;
}