#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floydWarshall(int n, const vector<vector<int>>& adj){
    vector<vector<int>> dist(n, vector<int>(n));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            dist[i][j] = adj[i][j];

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    return dist;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n, vector<int>(n));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> adj[i][j];

    vector<vector<int>> result = floydWarshall(n, adj);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout << (adj[i][j] - result[i][j]) << ' ';
        cout << '\n';
    }

    return 0;
}