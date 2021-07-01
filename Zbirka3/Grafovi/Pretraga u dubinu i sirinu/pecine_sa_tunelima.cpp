#include <bits/stdc++.h>
using namespace std;

int dfs(int v, const vector<vector<pair<int,int>>>& adj, bool visited[]){
    visited[v] = 1;
    int mind = 0;
    for(pair<int,int> p : adj[v])
        if(!visited[p.first])
            mind = min(mind, p.second + dfs(p.first, adj, visited));
    return mind;
}

int maxDepth(int gnd, const vector<vector<pair<int,int>>>& adj, int n){
    bool visited[n];
    memset(visited, 0, n);
    return (gnd + dfs(0, adj, visited));
}

int main()
{
    int gnd, n, m;
    cin >> gnd >> n >> m;
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, -w));
    }

    cout << maxDepth(gnd, adj, n) << endl;

    return 0;
}