#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int l, int r){
    int pivot = arr[r];
    int i=l;
    for(int j=l; j<r; j++){
        if(arr[j] < pivot)
            swap(arr[i++], arr[j]);
    }
    swap(arr[i], arr[r]);
    return i;
}

void quicksort(vector<int>& arr, int l, int r){
    if(l >= r) return;
    int p = partition(arr, l, r);
    quicksort(arr, l, p-1);
    quicksort(arr, p+1, r);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];

    quicksort(arr, 0, n-1);
    
    for(int i=0; i<n; i++)
        cout << arr[i] << '\n';

    return 0;
}