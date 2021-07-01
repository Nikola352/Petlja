#include <bits/stdc++.h>
using namespace std;

void dfs(int v, const vector<vector<int>>& adj, vector<bool>& visited, stack<int>& ts){
    if(visited[v]) return;
    visited[v] = true;
    for(int u : adj[v])
        dfs(u, adj, visited, ts);
    ts.push(v);
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n);
	for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
	}

	vector<bool> visited(n, false);
	stack<int> ts;
	for(int i=0; i<n; i++){
        dfs(i, adj, visited, ts);
	}

	while(!ts.empty()){
        cout << ts.top() << endl;
        ts.pop();
	}

	return 0;
}