#include <bits/stdc++.h>
using namespace std;

#define Graph vector<vector<pair<int,double>>>
const double INF = numeric_limits<double>::infinity();

bool comp(const pair<int,double>& a, const pair<int,double>& b){
    return (a.second > b.second);
}

double dijkstra(int n, const Graph& adj, int s, int e, vector<int>& parent){
    vector<bool> sptSet(n, false);
    vector<double> dist(n, INF);

    dist[s] = 0;

    priority_queue<pair<int,double>, vector<pair<int,double>>, decltype(&comp)> pq(comp); // min-heap
    for(int i=0; i<n; i++)
        pq.push(make_pair(i,dist[i]));

    while(!pq.empty()){
        int v = pq.top().first;
        pq.pop();

        if(sptSet[v]) continue;

        sptSet[v] = true;

        if(v == e) break;

        for(auto& u : adj[v]){
            if(!sptSet[u.first]){
                if(dist[v] + u.second < dist[u.first]){
                    dist[u.first] = dist[v] + u.second;
                    pq.push(make_pair(u.first, dist[u.first]));
                    parent[u.first] = v;
                }
            }
        }
    }

    return dist[e];
}

int main()
{
    int n, m;
    cin >> n >> m;
    Graph adj(n);
    for(int i=0; i<m; i++){
        int u, v;
        double w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }

    int s, e;
    cin >> s >> e;

    vector<int> parent(n);
    double result = dijkstra(n, adj, s, e, parent);
    if(result == INF)
        cout << "ne\n";
    else {
        cout << fixed << setprecision(5) << result << '\n';

        stack<int> st;
        int p = e;
        st.push(p);
        while(p != s){
            p = parent[p];
            st.push(p);
        }

        while(!st.empty()){
            cout << st.top() << ' ';
            st.pop();
        }
    }

    return 0;
}