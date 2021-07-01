#include <bits/stdc++.h>
using namespace std;

int getSum(int k, vector<int>& tree){
    int res = 0;
    while(k > 0){
        res += tree[k];
        k -= k & -k;
    }
    return res;
}

int findPos(int k, int n, vector<int>& tree){
    int l=1, r=n, lp=-1;
    while(l <= r){
        int m = l + (r-l)/2;
        int pot = getSum(m, tree);
        if(pot >= k){
            lp = m;
            r = m - 1;
        } else 
            l = m + 1;
    }
    return lp;
}

void update(int k, int val, int n, vector<int>& tree){
    while(k <= n){
        tree[k] += val;
        k += k & -k;
    }
}

vector<int> buildTree(int n){
    vector<int> tree(n+1, 0);
    for(int i=1; i<=n; i++)
        update(i, 1, n, tree);
    return tree;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> tree = buildTree(n);

    int p = 0;
    for(int i=1; i<=n; i++){
        int k = (getSum(p, tree) + i) % (n-i+1) + 1;
        p = findPos(k, n, tree);
        update(p, -1, n, tree);
        arr[p-1] = i;
    }

    for(int i=0; i<n; i++)
        cout << arr[i] << ' ';
    cout << '\n';

    return 0;
}