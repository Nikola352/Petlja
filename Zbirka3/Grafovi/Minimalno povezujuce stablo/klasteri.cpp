#include<bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> Edge;

int ds_find(int i, vector<int>& parent){
    if(parent[i] == i) return i;
    int res = ds_find(parent[i], parent);
    parent[i] = res;
    return res;
}

bool ds_union(int i, int j, vector<int>& parent, vector<int>& rank){
    int irep = ds_find(i, parent),
        jrep = ds_find(j, parent);
    if(irep == jrep) return false;
    if(rank[jrep] < rank[irep]) swap(irep, jrep);
    parent[irep] = jrep;
    if(rank[irep] == rank[jrep]) rank[jrep]++;
    return true;
}

int solve(int k, int n, int m, vector<Edge>& edges){
    vector<int> parent(n), rank(n);
    for(int i=0; i<n; i++){
        parent[i] = i;
        rank[i] = 0;
    }

    sort(edges.begin(), edges.end());

    int groups = n;
    
    for(int i=0; i<m; i++){
        if(ds_union(get<1>(edges[i]), get<2>(edges[i]), parent, rank)){
            groups--;
            if(groups < k) 
                return get<0>(edges[i]);
        }
    }
}

int main()
{
    int k, n, m;
    cin >> k >> n >> m;
    vector<Edge> roads;
    roads.reserve(n);
    for(int i=0; i<m; i++){
        int v, u, w;
        cin >> v >> u >> w;
        roads.emplace_back(w, v, u);
    } 
 
    cout << solve(k, n, m, roads) << endl;

    return 0;
}