#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> load(n, 0), unload(n, 0);
    for(int i=0; i<m; i++){
        int s, e, l;
        cin >> s >> e >> l;
        load[s] += l;
        unload[e] += l;
    }

    int currLoad = 0;
    for(int i=0; i<n; i++){
        currLoad += load[i];
        cout << currLoad << ' ';
        currLoad -= unload[i];
    }

    return 0;
}