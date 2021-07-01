#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
using namespace std;

typedef unsigned int uint; 

int rand_val(int l, int r){
    // returns a random integer from range [l,r]
    mt19937_64 rng;
    uniform_int_distribution<int> dist(l, r);
    return dist(rng);
}

uint nthel(vector<uint>& arr, int n){
    int l=0, r=arr.size()-1;
    while(1){
        swap(arr[r], arr[rand_val(l, r)]);
        uint pivot = arr[r];
        
        int i=l, j=r-1;
        while(i <= j){
            if(arr[i] < pivot) i++;
            else if(arr[j] > pivot) j--;
            else swap(arr[i++], arr[j--]);
        }

        int p = i;
        swap(arr[p], arr[r]);
        if(p < n)
            l = p + 1;
        else if(p > n)
            r = p - 1;
        else
            return arr[n];
    }
}

double median(vector<uint>& arr, int n){
    if(n & 1)
        return nthel(arr, n / 2);
    else
        return (((double)nthel(arr, n/2-1)+(double)nthel(arr, n/2))/2.0);
}

int main()
{
    int n;
    cin >> n;
    uint c0, c1;
    cin >> c0 >> c1;
    vector<uint> arr(n);
    cin >> arr[0];
    for(int i=1; i<n; i++)
        arr[i] = arr[i-1]*c0 + c1;

    cout << fixed << setprecision(2) << median(arr, n) << '\n';

    return 0;
}