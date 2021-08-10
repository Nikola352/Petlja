#include <bits/stdc++.h>
using namespace std;

vector<int> tree;

int getSum(int k){
    int res = 0;
    while(k > 0){
        res += tree[k];
        k -= k & -k;
    }
    return res;
}

int getRangeSum(int l, int r){
    return (getSum(r) - getSum(l-1));
}

void update(int k, int val){
    while(k < tree.size()){
        tree[k] += val;
        k += k & -k;
    }
}

void buildTree(int n, vector<int>& arr){
    tree.clear();
    tree.resize(n+1, 0);
    for(int i : arr)
        update(i, 1);
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
    
    buildTree(rnk, arr);

    vector<int> res(n);
    for(int i=0; i<n; i++){
        res[i] = getRangeSum(arr[i], rnk) - 1;
        update(arr[i], -1);
    }

    int q;
    cin >> q;
    while(q--){
        int d, k;
        cin >> d >> k;
        cout << (res[d] <= k ? "da" : "ne") << '\n';
    }

    return 0;
}