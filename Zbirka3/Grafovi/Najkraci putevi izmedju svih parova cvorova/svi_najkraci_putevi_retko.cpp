// O(n^2 log n) 
#include <bits/stdc++.h>
using namespace std;

#define Graph vector<vector<pair<int, int>>>
#define INF INT_MAX

int dijkstra(int s, const Graph& adj, int n){
    vector<bool> solved(n, false);
    vector<int> dist(n, INF);
    dist[s] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(int i=0; i<n; i++)
        pq.emplace(dist[i], i);

    while(!pq.empty()){
        int v = pq.top().second;
        pq.pop();

        if(solved[v]) continue;

        solved[v] = true;

        for(auto& u : adj[v]){
            if(!solved[u.first] && dist[v] + u.second < dist[u.first]){
                dist[u.first] = dist[v] + u.second;
                pq.emplace(dist[u.first], u.first);
            }
        }
    }

    int m = 0;
    for(auto& p : adj[s]){
        m = max(m, p.second - dist[p.first]);
    }

    return m;
}

int main()
{
    int n, m;
    cin >> n >> m;
    Graph adj(n);
    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }

    int maxs = 0;
    for(int i=0; i<n; i++)
        maxs = max(maxs, dijkstra(i, adj, n));

    cout << maxs << endl;

    return 0;
}