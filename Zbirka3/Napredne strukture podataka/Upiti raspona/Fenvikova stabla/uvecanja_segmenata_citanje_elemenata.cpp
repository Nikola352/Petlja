#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int getSum(int k, int n, const vi& tree){
    int res = 0;
    while (k > 0) {
        res += tree[k];
        k -= k & -k;
    }
    return res;
}

void update(int k, int val, int n, vi& tree){
    while(k <= n){
        tree[k] += val;
        k += k & -k;
    }
}

void updateRange(int a, int b, int val, int n, vi& tree){
    update(a+1, val, n, tree);
    update(b+2, -val, n, tree);
}

int main()
{
    int n;
    cin >> n;
    vi arr(n);

    vi tree(n+1, 0);

    int q;
    cin >> q;

    while(q--){
        char t;
        cin >> t;
        if(t == 'u'){
            int a, b, k;
            cin >> a >> b >> k;
            updateRange(a, b, k, n, tree);
        } else if(t == 'e'){
            int i;
            cin >> i;
            cout << getSum(i+1, n, tree) << '\n';
        }
    }

	return 0;
}