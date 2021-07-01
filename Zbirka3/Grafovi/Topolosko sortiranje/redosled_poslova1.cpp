#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(int n, const vector<vector<int>>& adj, vector<int>& indegree){
    vector<int> top_order;
    top_order.reserve(n);

    queue<int> q;
    for(int i=0; i<n; i++)
        if(indegree[i] == 0)
            q.push(i);

    while(!q.empty()){
        int v = q.front();
        q.pop();
        top_order.push_back(v);
        for(int u : adj[v])
            if(--indegree[u] == 0)
                q.push(u);
    }

    return top_order;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n);
	vector<int> indegree(n, 0);
	for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
        indegree[u]++;
	}

    vector<int> result = topologicalSort(n, adj, indegree);
    for(int i=0; i<n; i++)
        cout << result[i] << endl;

	return 0;
}