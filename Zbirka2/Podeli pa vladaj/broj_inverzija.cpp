#include <iostream>
#include <vector>
using namespace std;

int inversions(vector<int>& arr, int l, int r){
    if(l >= r) return 0;

    int m = l + (r-l)/2;
    int c = inversions(arr, l, m) + inversions(arr, m+1, r);

    vector<int> res;

    int i=l, j=m+1;
    while(i <= m && j <= r){
        if(arr[i] > arr[j]){
            c += m-i+1;
            res.push_back(arr[j++]);
        } else {
            res.push_back(arr[i++]);
        }
    }

    while(i <= m)
        res.push_back(arr[i++]);

    while(j <= r)
        res.push_back(arr[j++]);

    for(i=0; i<res.size(); i++)
        arr[i+l] = res[i];

    return c;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];

    cout << inversions(arr, 0, n-1) << '\n';

    return 0;
}