#include<bits/stdc++.h>
using namespace std;

struct Edge{
    float dist;
    int r1, r2;
};

bool comp(const Edge& e1, const Edge& e2){
    return (e1.dist < e2.dist);
}

int find(int i, vector<int>& parent){
    if(parent[i] == i) return i;
    int res = find(parent[i], parent);
    parent[i] = res;
    return res;
}

void Union(int i, int j, vector<int>& parent, vector<int>& rank){
    int irep = find(i, parent),
        jrep = find(j, parent);
    
    if(irep == jrep) return;

    if(rank[jrep] < rank[irep]) swap(irep, jrep);

    parent[irep] = jrep;

    if(rank[irep] == rank[jrep]) rank[jrep]++;
}

float kruskal(int n, int m, vector<Edge>& edges){
    vector<int> parent(n), rank(n);
    for(int i=0; i<n; i++){
        parent[i] = i;
        rank[i] = 1;
    }

    float res = 0.0f;

    sort(edges.begin(), edges.end(), comp);

    for(int i=0; i<m; i++){
        int rep1 = find(edges[i].r1, parent),
            rep2 = find(edges[i].r2, parent);
        if(rep1 != rep2){
            res += edges[i].dist;
            Union(rep1, rep2, parent, rank);
        } 
    }

    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for(int i=0; i<m; i++)
        cin >> edges[i].r1 >> edges[i].r2 >> edges[i].dist;

    cout << fixed << setprecision(1) << kruskal(n, m, edges);

    return 0;
}