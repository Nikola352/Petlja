#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> sum(n);
    int s = 0;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        s += x;
        sum[i] = s;
    }

    int m;
    cin >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        int t = sum[b];
        if(a>0) t -= sum[a-1];
        cout << t << '\n';
    }

    return 0;
}