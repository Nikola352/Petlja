#include <bits/stdc++.h>
using namespace std;

bool prime(int n){
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n%2==0 || n%3==0) return false;
    for(int i=5; i*i<=n; i+=6){
        if(n % i == 0) return false;
        if(n % (i+2) == 0) return false;
    }
    return true;
}

int smallerPrime(int n){
    int n0 = n;
    if(n % 6 == 0) n -= 6;
    else n -= n % 6;
    while(n > 1){
        if(n+5<n0 && prime(n+5))
            return (n+5);
        if(n+1<n0 && prime(n+1))
            return (n+1);
        n -= 6;
    }
    return -1000000000;
}

int largerPrime(int n){
    int n0 = n;
    if(n % 6 == 0) n += 6;
    else n += 6 - (n % 6);
    while(n < INT_MAX){
        if(n-5>n0 && prime(n-5))
            return (n-5);
        if(n-1>n0 && prime(n-1))
            return (n-1);
        n += 6;
    }
    return INT_MAX;
}

void closestPrime(int n){
    if(prime(n)){
        cout << "prost broj " << n;
        return;
    }
    int sp = smallerPrime(n),
        lp = largerPrime(n);
    if(n-sp == lp-n){
        cout << "dva broja " << sp << ' ' << lp;
    } else if(n-sp < lp-n){
        cout << "manji broj " << sp;
    } else {
        cout << "veci broj " << lp;
    }
}

int main()
{
    int n;
    cin >> n;

    closestPrime(n);

    return 0;
}