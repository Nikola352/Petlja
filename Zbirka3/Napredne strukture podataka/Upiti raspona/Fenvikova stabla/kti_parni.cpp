#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int getSum(int k, int n, const vi& tree){
    int res = 0;
    while(k > 0){
        res += tree[k];
        k -= k & -k;
    }
    return res;
}

int findEvenPos(int k, int n, const vi& tree){
    int l=1, r=n, lp=-1;
    while(l <= r){
        int m = l + (r-l)/2;
        int val = getSum(m, n, tree);
        if(val == k){
            lp = m;
            r = m - 1;
        } else if(val < k){
            l = m + 1;
        } else {
            r = r - 1;
        }
    }
    return lp;
}

void update(int k, int val, int n, vi& tree){
    while(k <= n){
        tree[k] += val;
        k += k & -k;
    }
}

vi buildTree(int n){
    vi tree(n+1);
    for(int i=0; i<n; i++)
        update(i+1, 1, n, tree);
    return tree;
}

int main()
{
    int n;
    cin >> n;
    vi arr(n, 0);

    vi tree = buildTree(n);

    int m;
    cin >> m;

    while(m--){
        char q;
        cin >> q;
        if(q == 'u'){
            int p, x;
            cin >> p >> x;
            if((arr[p-1]-x) & 1){
                if(x % 2 == 0)
                    update(p, 1, n, tree);
                else 
                    update(p, -1, n, tree);
            }
            arr[p-1] = x;
        } else if(q == 'c'){
            int k;
            cin >> k;
            int pos = findEvenPos(k, n, tree);
            if(pos == -1) cout << "-\n";
            else cout << pos << '\n';
        }
    }

	return 0;
}