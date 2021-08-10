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

void update(int k, int val){
    while(k < tree.size()){
        tree[k] += val;
        k += k & -k;
    }
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
    
    tree.clear();
    tree.resize(rnk+1, 0);

    int res = 0;
    for(int i=n-1; i>=0; i--){
        res += getSum(arr[i]-1);
        update(arr[i], 1);
    }

    cout << res << '\n';

    return 0;
}