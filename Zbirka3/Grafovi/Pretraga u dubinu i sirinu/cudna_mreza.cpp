#include <bits/stdc++.h>
using namespace std;

void dfs(int v, const vector<vector<int>>& adj, vector<bool>& visited, int& computers){
    visited[v] = true;
    computers++;
    for(int u : adj[v]){
        if(!visited[u])
            dfs(u, adj, visited, computers);
    }
}

int main()
{
    int cs, ck, n, m;
    cin >> cs >> ck >> n >> m;
    vector<vector<int>> adj(n);
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n, false);
    int components=0, cables=0;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            int computers=0;
            dfs(i, adj, visited, computers);
            components++;
            cables += computers - 1;
        }
    }

    if(cs <= ck) cout << cs*(cables + components);
    else cout << (cs*components + ck*cables) << endl;

    return 0;
}