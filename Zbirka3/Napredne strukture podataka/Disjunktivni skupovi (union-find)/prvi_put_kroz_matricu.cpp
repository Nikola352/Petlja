#include <bits/stdc++.h>
using namespace std;

typedef vector<bool> vb;
typedef vector<vb> vbb;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<pair<int,int>> vpi;
typedef vector<vpi> vvpi;

pair<int, int> df_find(int i, int j, vvpi& parent){
    if(parent[i][j] == make_pair(i,j))
        return parent[i][j];
    pair<int, int> res = df_find(parent[i][j].first, parent[i][j].second, parent);
    parent[i][j] = res;
    return res;
}

void df_union(int i1, int j1, int i2, int j2, vvpi& parent, vii& rank){
    int i1rep, j1rep, i2rep, j2rep;
    tie(i1rep, j1rep) = df_find(i1, j1, parent);
    tie(i2rep, j2rep) = df_find(i2, j2, parent);
    if(rank[i1rep][j1rep] > rank[i2rep][j2rep]){
        swap(i1rep, i2rep);
        swap(j1rep, j2rep);
    }
    parent[i1rep][j1rep] = make_pair(i2rep, j2rep);
    if(rank[i1rep][j1rep] == rank[i2rep][j2rep])
        rank[i2rep][j2rep]++;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vbb arr(n, vb(n, 0));
    vvpi parent(n, vpi(n));
    vii rank(n, vi(n, 0));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            parent[i][j] = make_pair(i, j);

    for(int i=0; i<n; i++){
        parent[0][i] = make_pair(0, 0);
        parent[n-1][i] = make_pair(n-1, 0);
    } 

    int res = -1;

    for(int i=0; i<m; i++){
        int r, c;
        cin >> r >> c;
        if(res == -1){
            arr[r][c] = 1;
            if(r>0 && arr[r-1][c])
                df_union(r-1, c, r, c, parent, rank);
            if(r<n-1 && arr[r+1][c])
                df_union(r+1, c, r, c, parent, rank);
            if(c>0 && arr[r][c-1])
                df_union(r, c-1, r, c, parent, rank);
            if(c<n-1 && arr[r][c+1])
                df_union(r, c+1, r, c, parent, rank);
            if(df_find(0, 0, parent) == df_find(n-1, 0, parent))
                res = i+1;
        }
    }

    cout << res << '\n';

    return 0;
}