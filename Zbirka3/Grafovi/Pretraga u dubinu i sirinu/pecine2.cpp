// mora biti drvo
#include <bits/stdc++.h>
using namespace std;

int dfs(int v, const vector<vector<pair<int,int>>>& adj){
    int mind = 0;
    for(pair<int,int> p : adj[v])
        mind = min(mind, p.second + dfs(p.first, adj));
    return mind;
}

int main()
{
    int gnd, n;
    cin >> gnd >> n;
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0; i<n-1; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
    }

    cout << (gnd + dfs(0, adj)) << endl;

    return 0;
}