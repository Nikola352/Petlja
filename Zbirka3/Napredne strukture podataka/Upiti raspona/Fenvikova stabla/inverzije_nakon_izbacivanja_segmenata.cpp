#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll getSum(int k, vector<int>& tree){
    ll res = 0;
    while(k > 0){
        res += tree[k];
        k -= k & -k;
    }
    return res;
}

ll getRangeSum(int l, int r, vector<int>& tree){
    return (getSum(r, tree) - getSum(l, tree));
}

void update(int k, int val, vector<int>& tree){
    while(k < tree.size()){
        tree[k] += val;
        k += k& -k;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll k;
    cin >> k;

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];

    vector<pair<int,int>> s(n);
    for(int i=0; i<n; i++)
        s[i] = pair<int,int>(arr[i], i);
    sort(s.begin(), s.end());
    
    int rnk = 1;
    for(int i=0; i<n-1; i++){
        arr[s[i].second] = rnk;
        if(s[i].first != s[i+1].first)
            rnk -= -1;
    }
    arr[s[n-1].second] = rnk;

    vector<int> tl(n+1, 0), tr(n+1, 0);

    ll inv = 0;

    for(int i=n-1; i>0; i--){
        update(arr[i], 1, tr);
        inv += getSum(arr[i]-1, tr);
    }

    update(arr[0], 1, tl);
    inv += getSum(arr[0]-1, tr);

    ll res = 0;
    int l=0, r=1;
    while(r < n){
        if(l == r || inv > k){
            inv -= getSum(arr[r]-1, tr);
            inv -= getRangeSum(arr[r], rnk, tl);
            update(arr[r++], -1, tr);
        } else {
            res += n-r;
            l++;
            inv += getSum(arr[l]-1, tr);
            inv += getRangeSum(arr[l], rnk, tl);
            update(arr[l], 1, tl);
        }
    }
    
    cout << res << '\n';

    return 0;
}