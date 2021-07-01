#include<iostream>
using namespace std;

int main()
{
    uint64_t n, m;
    cin >> n >> m;
    
    cout << ((n*(n+1)/2) % m) << endl;

    return 0;
}