#include <bits/stdc++.h>
using namespace std;

struct Seg{
    int idx, l, r;
};

bool comp(const Seg& a, const Seg& b){
    return (a.r < b.r);
}

vector<int> tree;

int getSum(int k){
    int res = 0;
    for(; k>0; k -= k & -k)
        res += tree[k];
    return res;
}

int getRangeSum(int l, int r){
    return (getSum(r) - getSum(l-1));
}

void update(int k, int val){
    for(; k<tree.size(); k += k & -k)
        tree[k] += val;
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

    int m;
    cin >> m;
    vector<Seg> qrs(m);
    for(int i=0; i<m; i++){
        cin >> qrs[i].l >> qrs[i].r;
        qrs[i].idx = i;
    }
    sort(qrs.begin(), qrs.end(), comp);
    vector<int> res(m);

    tree.clear();
    tree.resize(n+1, 0);

    unordered_map<int,int> mp;

    int cr = 0;
    for(int i=0; i<m; i++){
        while(cr < qrs[i].r){
            if(mp.find(arr[cr]) != mp.end())
                update(mp[arr[cr]]+1, -1);
            mp[arr[cr]] = cr;
            update(++cr, 1);
        }
        res[qrs[i].idx] = getRangeSum(qrs[i].l, qrs[i].r);
    }

    for(int i=0; i<m; i++)
        cout << res[i] << '\n';

    return 0;
}