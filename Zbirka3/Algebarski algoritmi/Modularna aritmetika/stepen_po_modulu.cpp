#include<bits/stdc++.h>
using namespace std;

typedef uint64_t ull;

ull exp(ull b, ull e, ull mod){
    if(e == 0) return 1;
    b %= mod;
    ull res = 1;
    while(e > 0){
        if(e & 1) res = (res%mod * b%mod) % mod;
        b = (b%mod * b%mod) % mod;
        e /= 2;
    }
    return res;
}

int main()
{
    ull a, n, m;
    cin >> a >> n >> m;

    cout << exp(a, n, m) << endl;

    return 0;
}