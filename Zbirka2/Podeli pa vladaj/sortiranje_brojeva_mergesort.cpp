#include <iostream>
#include <vector>
using namespace std;

void mrgsort(vector<int>& arr, int l, int r){
    if(l >= r) return;

    int m = l + (r-l)/2;
    mrgsort(arr, l, m);
    mrgsort(arr, m+1, r);

    int n = r - l + 1;

    vector<int> res(n);
    int i=0, j=l, k=m+1;
    while(j <= m && k <= r){
        if(arr[j] < arr[k])
            res[i++] = arr[j++];
        else
            res[i++] = arr[k++];
    }

    while(j <= m)
        res[i++] = arr[j++];

    while(k <= r)
        res[i++] = arr[k++];

    for(i=0; i<n; i++)
        arr[i+l] = res[i];
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];

    mrgsort(arr, 0, n-1);
    
    for(int i=0; i<n; i++)
        cout << arr[i] << '\n';

    return 0;
}