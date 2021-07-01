#include <iostream>
#include <vector>
#include <random>
using namespace std;

int rand_val(int l, int r){
    mt19937_64 rng;
    uniform_int_distribution<int> dist(l, r);
    return dist(rng);
}

int quickSelect(vector<int>& arr, int n, int k){
    int l=0, r=n-1;
    while(1){
        swap(arr[r], arr[rand_val(l, r)]);
        int pivot = arr[r];
        int i=l, j=r-1;
        while(i <= j){
            if(arr[i] > pivot) i++;
            else if(arr[j] < pivot) j--;
            else swap(arr[i++], arr[j--]);
        }
        swap(arr[i], arr[r]);
        if(i < k)
            l = i + 1;
        else if(i > k)
            r = i - 1;
        else {
            int res = 0;
            for(i=0; i<=k; i++)
                res += arr[i];
            return res;
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];

    cout << quickSelect(arr, n, k-1) << '\n';

    return 0;
}