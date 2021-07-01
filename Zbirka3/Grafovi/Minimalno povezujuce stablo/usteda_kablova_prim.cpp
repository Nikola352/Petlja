#include<bits/stdc++.h>
using namespace std;

#define inf INFINITY
typedef vector<vector<pair<float, int>>> Graph;

float prim(int n, const Graph& adj){
    vector<bool> mstSet(n, false);
    vector<float> key(n, inf);
    key[0] = 0;

    priority_queue<pair<float, int>, vector<pair<float,int>>, greater<pair<float,int>>> pq;
    for(int i=0; i<n; i++)
        pq.emplace(key[i], i);
    
    float res = 0.0f;

    while(!pq.empty()){
        int v = pq.top().second;
        pq.pop();

        if(mstSet[v]) continue;

        mstSet[v] = true;
        res += key[v];

        for(auto& u : adj[v]){
            if(!mstSet[u.second] && u.first < key[u.second]){
                key[u.second] = u.first;
                pq.emplace(key[u.second], u.second);
            }
        }
    }

    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    Graph adj(n);
    for(int i=0; i<m; i++){
        int u, v;
        float w;
        cin >> u >> v >> w;
        adj[u].emplace_back(w, v);
        adj[v].emplace_back(w, u);
    }

    cout << fixed << setprecision(1) << prim(n, adj) << endl;

    return 0;
}