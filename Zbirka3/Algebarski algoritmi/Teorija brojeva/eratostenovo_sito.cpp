#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000;

vector<int> sieve(int n, vector<bool>& prime){
    prime[1] = false;
    int p = 2;
    while(p <= n){
        if(prime[p]){
            for(int i=p*p; i<=n; i+=p)
                prime[i] = false;
        }
        p++;
    }
    vector<int> res;
    for(int i=2; i<=n; i++){
        if(prime[i]) res.push_back(i);
    }
    return res;
}

void segmentedSieve(int a, int b, const vector<int>& primes){
    vector<bool> prime(b-a+1, true);
    if(a==1) prime[0] = false;
    for(int p : primes){
        int start = max(a, p*p);
        start += ((start%p==0) ? 0 : (p - start%p));
        for(int i=start; i<=b; i+=p){
            prime[i-a] = false;
        }
    }
    int c=0, s=0;
    for(int i=a; i<=b; i++){
        if(prime[i-a]){
            c++;
            s += i;
            s %= MOD;
        }
    }
    cout << c << ' ' << s << '\n';
}

int main()
{
    int a, b;
    cin >> a >> b;

    int np = ceil(sqrt(b));
    vector<bool> prime(np+1, true);

    vector<int> primes = sieve(np, prime);

    segmentedSieve(a, b, primes);

    return 0;
}