#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;

vii solve(vi& arr, int l, int r){
    if(l == r)
        return vii(1, pii(0, l));

    int m = l + (r-l)/2;
    vii r1 = solve(arr, l, m),
        r2 = solve(arr, m+1, r);

    int n1=r1.size(), n2=r2.size();

    vi rarr;
    vii res;

    int i1=l, i2=m+1;
    while(i1 <= m && i2 <= r){
        if(arr[i1] <= arr[i2]){
            rarr.push_back(arr[i1]);
            res.emplace_back(r1[i1-l].first+r-i2+1, r1[i1-l].second);
            i1++;
        } else {
            rarr.push_back(arr[i2]);
            res.push_back(r2[i2-m-1]);
            i2++;
        }
    }

    while(i1 <= m){
        rarr.push_back(arr[i1]);
        res.emplace_back(r1[i1-l].first, r1[i1-l].second);
        i1++;
    }

    while(i2 <= r){
        rarr.push_back(arr[i2]);
        res.push_back(r2[i2-m-1]);
        i2++;
    }

    for(int i=l; i<=r; i++)
        arr[i] = rarr[i-l];

    return res;
}

int main()
{
    int n;
    cin >> n;
    vi arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];

    vi inipos(n);
    for(int i=0; i<n; i++)
        inipos[i] = i;

    vii rval = solve(arr, 0, n-1);
    vi res(n);
    for(int i=0; i<n; i++)
        res[rval[i].second] = rval[i].first;

    int q;
    cin >> q;
    while(q--){
        int d, k;
        cin >> d >> k;
        cout << (res[d] <= k ? "da\n" : "ne\n");
    }

    return 0;
}