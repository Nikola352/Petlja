#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9;

int getSum(int k, vector<int>& tree){
    int res = 0;
    while(k > 0){
        res += tree[k];
        k -= k & -k;
    }
    return res;
}

int getRangeSum(int l, int r, vector<int>& tree){
    return (getSum(r, tree) - getSum(l-1, tree));
}

void update(int k, int val, vector<int>& tree){
    while(k < tree.size()){
        tree[k] += val;
        k += k & -k;
    }
}

vector<int> buildTree(int n, vector<int>& arr){
    vector<int> tree(n+1, 0);
    for(int i : arr)
        update(i, 1, tree);
    return tree;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);
    vector<pair<int,int>> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    int rnk = 1;
    arr[v[0].second] = 1;
    for(int i=1; i<n; i++){
        if(v[i].first > v[i-1].first) rnk++;
        arr[v[i].second] = rnk;
    }
    
    vector<int> lt(rnk+1, 0);
    vector<int> rt = buildTree(rnk, arr);

    int res = 0;
    for(int i=0; i<n; i++){
        update(arr[i], -1, rt);
        res += (getSum(arr[i]-1, lt) * getRangeSum(arr[i]+1, rnk, rt)) % MOD;
        res %= MOD;
        update(arr[i], 1, lt);
    }

    cout << res << '\n';

    return 0;
}