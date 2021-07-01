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

int getRangeSum(int a, int b, int n, const vi& tree){
    return(getSum(b, n, tree) - getSum(a-1, n, tree));
}

void update(int k, int val, int n, vi& tree){
    while(k <= n){
        tree[k] += val;
        k += k & -k;
    }
}

void setToVal(int k, int val, int n, vi& tree){
    update(k, val - getRangeSum(k, k, n, tree), n, tree);
}

vi buildTree(int n, const vi& arr){
    vi tree(n+1, 0);
    for(int i=1; i<=n; i++){
        update(i, arr[i-1], n, tree);
    }
    return tree;
}

int main()
{
    int n;
    cin >> n;
    vi arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];

    vi tree = buildTree(n, arr);

    int m;
    cin >> m;

    while(m--){
        char t;
        cin >> t;
        if(t == 'p'){
            int i, v;
            cin >> i >> v;
            setToVal(i+1, v, n, tree);
        } else if(t == 'z'){
            int a, b;
            cin >> a >> b;
            cout << getRangeSum(a+1, b+1, n, tree) << '\n';
        }
    }

	return 0;
}