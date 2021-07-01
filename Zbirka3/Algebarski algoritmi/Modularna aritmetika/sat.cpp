#include<bits/stdc++.h>
using namespace std;

int main()
{
    int h, m;
    cin >> h >> m;

    cout << ((h+12-1) % 12 + 1) << ':' << m;

    return 0;
}