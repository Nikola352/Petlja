#include <iostream>
#include <vector>
using namespace std;

struct Seg{
    int md, mx, mn;
    Seg(){}
    Seg(int e) : md(0), mx(e), mn(e) {}
};

int max(int a, int b){
    if(a > b) return a;
    return b;
}

int min(int a, int b){
    if(a < b) return a;
    return b;
}

Seg solve(const vector<int>& arr, int l, int r){
    if(l == r) return Seg(arr[l]);

    int m = l + (r-l)/2;

    Seg left = solve(arr, l, m),
        right = solve(arr, m+1, r);

    Seg res;
    res.mx = max(left.mx, right.mx);
    res.mn = min(left.mn, right.mn);
    res.md = max(left.md, right.md);
    res.md = max(res.md, right.mx - left.mn);

    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];

    cout << solve(arr, 0, n-1).md << '\n';

    return 0;
}