#include <bits/stdc++.h>
using namespace std;

void build(const vector<int>& arr, vector<int>& segtree, int v, int tl, int tr){
    if(tl == tr){
        segtree[v] = arr[tl];
    } else {
        int tm = tl + (tr-tl)/2;
        build(arr, segtree, 2*v+1, tl, tm);
        build(arr, segtree, 2*v+2, tm+1, tr);
        segtree[v] = segtree[2*v+1] + segtree[2*v+2];
    }
}

int segSum(const vector<int>& segtree, int v, int tl, int tr, int l, int r){
    if(l > r)
        return 0;
    if(l == tl && r == tr)
        return segtree[v];
    int tm = tl + (tr-tl)/2;
    return (
        segSum(segtree, 2*v+1, tl, tm, l, min(r, tm)) 
        + segSum(segtree, 2*v+2, tm+1, tr, max(l, tm+1), r)
    );
}

void update(vector<int>& segtree, int v, int tl, int tr, int pos, int val){
    if(tl == tr){
        segtree[v] = val;
    } else {
        int tm = tl + (tr-tl)/2;
        if(pos <= tm)
            update(segtree, 2*v+1, tl, tm, pos, val);
        else 
            update(segtree, 2*v+2, tm+1, tr, pos, val);
        segtree[v] = segtree[2*v+1] + segtree[2*v+2];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];

    vector<int> segtree(4*n);
    build(arr, segtree, 0, 0, n-1);
    
    int m;
    cin >> m;
    for(int i=0; i<m; i++){
        char q;
        cin >> q;
        if(q == 'p'){
            int pos, val;
            cin >> pos >> val;
            update(segtree, 0, 0, n-1, pos, val);
            arr[pos] = val; // nepotrebno za ovaj zadatak
        } else if(q == 'z'){
            int a, b;
            cin >> a >> b;
            cout << segSum(segtree, 0, 0, n-1, a, b) << '\n';
        }
    }

    return 0;
}