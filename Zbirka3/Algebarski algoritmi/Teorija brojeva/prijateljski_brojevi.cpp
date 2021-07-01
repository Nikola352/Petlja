#include <bits/stdc++.h>
using namespace std;

int divisorSum(int n){
    int n0 = n, res = 1;
    int p = 2;
    while(p*p <= n){
        int spi = 1;
        while(n % p == 0){
            spi = spi*p + 1;
            n /= p;
        }
        res *= spi;
        p++;
    }
    if(n > 1) res *= (1 + n);
    return (res - n0);
}

int main()
{
    int a, b;
    cin >> a >> b;

    for(int i=a; i<=b; i++){
        int dsum = divisorSum(i);
        if(dsum>=a && dsum<=b && i<=dsum && divisorSum(dsum) == i)
            cout << i << ' ' << dsum << endl;
    }

    return 0;
}