#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m;
    cin >> m;
    unordered_map<string, vector<string>> adj;
    unordered_map<string, bool> visited;
    for(int i=0; i<m; i++){
        string a1, a2;
        cin >> a1 >> a2;
        adj[a1].push_back(a2);
        visited[a1] = false;
        visited[a2] = false;
    }

    int k;
    cin >> k;
    for(int i=0; i<k; i++){
        for(auto& j : visited) j.second = false;

        string a1, a2;
        cin >> a1 >> a2;

        if(a1 == a2){
            cout << "ne\n";
            continue;
        }

        queue<pair<string,int>> q;
        q.push(make_pair(a1, 0));

        bool canReach = false;

        while(!q.empty()){
            string u = q.front().first;
            int dist = q.front().second;
            q.pop();
            visited[u] = true;

            if(u == a2){
                cout << dist << endl;
                canReach = true;
                break;
            }

            for(string v : adj[u]){
                if(!visited[v]){
                    q.push(make_pair(v, dist+1));
                }
            }
        }

        if(!canReach) cout << "ne\n";

    }

    return 0;
}