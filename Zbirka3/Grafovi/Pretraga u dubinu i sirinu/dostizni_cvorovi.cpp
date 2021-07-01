#include <bits/stdc++.h>
using namespace std;

void dfs(int s, int e, const vector<vector<int>>& adj, bool visited[], bool& reached){
    visited[s] = true;
    if(s == e){
        reached = true;
        return;
    }
    for(auto it=adj[s].begin(); it!=adj[s].end(); it++){
        if(!visited[*it])
            dfs(*it, e, adj, visited, reached);
    }
}

bool povezan(int s, int e, const vector<vector<int>>& adj, int n){
    bool visited[n];
    memset(visited, 0, n);
    bool reached = false;
    dfs(s, e, adj, visited, reached);
    return reached;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[--u].push_back(--v);
    }

    int p;
    cin >> p;
    for(int i=0; i<p; i++){
        int s, e;
        cin >> s >> e;
        cout << (povezan(--s, --e, adj, n) ? "da" : "ne") << endl;
    }

    return 0;
}