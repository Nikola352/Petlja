#include<bits/stdc++.h>
using namespace std;

bool perfect(int n){
    int s = 1;
    for(int i=2; i*i<n; i++){
        if(n % i == 0){
            s += i + n/i;
        }
    }
    
    int r = (int)sqrt(n);
    if(r*r == n)
        s += r;

    return (s == n);
}

int minPerfect(int n, int k){ 
    // [n-k, n+k]
    for(int i=n-k; i<=n+k; i++){
        if(perfect(i)) return i;
    }
    return -1;
}

int main()
{
    int n, k;
    cin >> n >> k;

    int res = minPerfect(n, k);
    
    if(res == -1) cout << "NE";
    else cout << res;

    return 0;
}