#include<iostream>
using namespace std;

int main()
{
    uint64_t n, m;
    cin >> n >> m;
    
    cout << ( n%2==0 ? ((n/2*(n+1)) % m) : (((n+1)/2*n) % m) )<< endl;

    return 0;
}