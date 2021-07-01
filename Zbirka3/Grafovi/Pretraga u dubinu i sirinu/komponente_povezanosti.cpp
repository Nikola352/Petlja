#include <bits/stdc++.h>
using namespace std;

void dfs(int v, const vector<vector<int>>& adj, vector<bool>& visited, vector<int>& result, int component){
	visited[v] = true;
	result[v] = component;
	for(int u : adj[v])
		if(!visited[u]) 
			dfs(u, adj, visited, result, component);
}

int main()
{
	int v, e;
	cin >> v >> e;
	vector<vector<int>> adj(v);
	for(int i=0; i<e; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<bool> visited(v, false);
	int component = 1;
	vector<int> result(v);
	for(int i=0; i<v; i++){
		if(!visited[i]){
			dfs(i, adj, visited, result, component);
			component++;
		}
	}

	for(int i=0; i<v; i++)
		cout << result[i] << ' ';

	return 0;
}