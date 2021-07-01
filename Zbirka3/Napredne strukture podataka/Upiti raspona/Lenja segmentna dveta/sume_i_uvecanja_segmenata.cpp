#include <bits/stdc++.h>
using namespace std;

vector<int> tree, lazy;

void push(int v, int tl, int tm, int tr){
    tree[2*v+1] += lazy[v]*(tm-tl+1);
    lazy[2*v+1] += lazy[v];
    tree[2*v+2] += lazy[v]*(tr-tm);
    lazy[2*v+2] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int val){
    if(l > r) return;
    if(l == tl && r == tr){
        tree[v] += val*(tr-tl+1);
        lazy[v] += val;
    } else {
        int tm = tl + (tr-tl)/2;
        push(v, tl, tm, tr);
        update(2*v+1, tl, tm, l, min(r, tm), val);
        update(2*v+2, tm+1, tr, max(l, tm+1), r, val);
        tree[v] = tree[2*v+1] + tree[2*v+2];
    }
}

int query(int v, int tl, int tr, int l, int r){
    if(l > r) return 0;
    if(l == tl && r == tr)
        return tree[v];
    int tm = tl + (tr-tl)/2;
    push(v, tl, tm, tr);
    return (
        query(2*v+1, tl, tm, l, min(r, tm)) +
        query(2*v+2, tm+1, tr, max(l, tm+1), r)
    );
}

void buildTree(const vector<int>& arr, int v, int tl, int tr){
    if(tl == tr){
        tree[v] = arr[tl];
    } else {
        int tm = tl + (tr-tl)/2;
        buildTree(arr, 2*v+1, tl, tm);
        buildTree(arr, 2*v+2, tm+1, tr);
        tree[v] = tree[2*v+1] + tree[2*v+2];
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

    tree.resize(4*n, 0);
    lazy.resize(4*n, 0);

    buildTree(arr, 0, 0, n-1);

    int m;
    cin >> m;

    while(m--){
        char q;
        cin >> q;
        if(q == 'u'){
            int a, b, v;
            cin >> a >> b >> v;
            update(0, 0, n-1, a, b, v);
        } else if(q == 'z'){
            int a, b;
            cin >> a >> b;
            cout << query(0, 0, n-1, a, b) << '\n';
        }
    }

    return 0;
}