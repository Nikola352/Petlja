#include <bits/stdc++.h>
using namespace std;

vector<int> sieve(int n, vector<bool>& prime){
    prime[0] = prime[1] = false;
    int p = 2;
    while(p*p <= n){
        if(prime[p])
            for(int i=p*p; i<=n; i+=p)
                prime[i] = false;
        p++;
    }
    vector<int> primes;
    for(int i=2; i<=n; i++){
        if(prime[i])
            primes.push_back(i);
    }
    return primes;
}

int numPairs(int n){
    vector<bool> prime(n+1, true);
    vector<int> primes = sieve(n, prime);
    int c=0;
    for(int i=0; i<primes.size(); i++){
        if(2 + primes[i] <= n && prime[2+primes[i]])
            c++;
    }
    return c;
}

int main()
{
    int n;
    cin >> n;

    cout << numPairs(n) << endl;

    return 0;
}