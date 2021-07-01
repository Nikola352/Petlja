#include <iostream>
#include <vector>
using namespace std;

struct Seg{
    int sum, lsum, rsum, msum;
    Seg(){}
    Seg(int sum) : sum(sum), lsum(sum), rsum(sum), msum(sum) {}
    Seg(int sum, int lsum, int rsum, int msum) : sum(sum), lsum(lsum), rsum(rsum), msum(msum) {}
};

Seg solve(const vector<int>& arr, int l, int r){
    if(l == r){
        Seg res(arr[l]);
        return res;
    }

    int m = l + (r-l) / 2;

    Seg left = solve(arr, l, m),
        right = solve(arr, m+1, r);

    Seg res;
    res.sum = left.sum + right.sum;
    res.lsum = max(left.lsum, left.sum + right.lsum);
    res.rsum = max(right.rsum, right.sum + left.rsum);
    res.msum = left.rsum + right.lsum;
    if(left.msum > res.msum)
        res.msum = left.msum;
    if(right.msum > res.msum)
        res.msum = right.msum;

    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];

    cout << solve(arr, 0, n-1).msum << '\n';

    return 0;
}