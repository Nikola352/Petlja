#include <iostream>
#include <vector>
using namespace std;

struct Elem{
    int val, ll, gr;
    Elem(){
        val = ll = gr = 0;
    }
    Elem(int val, int ll, int gr)
    : val(val), ll(ll), gr(gr) {}
};

const int MOD = 1e9;

int solve(vector<Elem>& arr, int l, int r){
    if(l == r) return 0;
    if(r-l == 1){
        if(arr[l].val < arr[r].val){
            arr[l].gr = 1;
            arr[r].ll = 1;
        } else {
            swap(arr[l], arr[r]);
        }
        return 0;
    }

    int m = l + (r-l)/2;

    int res = solve(arr, l, m) + solve(arr, m+1, r);

    vector<Elem> rarr;

    int i = l, j = m+1;
    while(i <= m && j <= r){
        if(arr[i].val < arr[j].val){
            res += (arr[i].ll * (r-j+1)) % MOD;
            res %= MOD;
            rarr.emplace_back(arr[i].val, arr[i].ll, arr[i].gr+r-j+1);
            i++;
        } else {
            res += ((i-l) * arr[j].gr) % MOD;
            res %= MOD;
            rarr.emplace_back(arr[j].val, arr[j].ll+i-l, arr[j].gr);
            j++;
        } 
    }

    while(i <= m)
        rarr.push_back(arr[i++]);
    while(j <= r){
        res += ((m+1-l) * arr[j].gr) % MOD;
        res %= MOD;
        rarr.emplace_back(arr[j].val, arr[j].ll+m+1-l, arr[j].gr);
        j++;
    }

    for(i=l; i<=r; i++)
        arr[i] = rarr[i-l];

    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<Elem> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i].val;

    cout << solve(arr, 0, n-1) << '\n';

    return 0;
}