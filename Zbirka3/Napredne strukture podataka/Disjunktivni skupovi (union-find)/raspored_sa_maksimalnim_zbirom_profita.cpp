#include <bits/stdc++.h>
using namespace std;

int ds_find(int i, vector<int>& parent){
    int x = i;
    while(x != parent[x]){
        x = parent[x];
    }
    parent[i] = x;
    return x;
}

void ds_union(int i, int j, vector<int>& parent){
    parent[i] = j;
}

bool comp(const pair<int, int>& a, const pair<int, int>& b){
    return (a.first > b.first);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> arr;
    arr.reserve(n);
    for(int i=0; i<n; i++){
        int rok, profit;
        cin >> rok >> profit;
        arr.emplace_back(profit, rok);
    }

    sort(arr.begin(), arr.end(), comp);

    vector<int> parent(n+1);
    for(int i=0; i<=n; i++)
        parent[i] = i;

    int s = 0;

    for(int i=0; i<n; i++){
        int rep = ds_find(arr[i].second, parent);
        if(rep != 0){
            s += arr[i].first;
            ds_union(rep, rep-1, parent);
        }
    }

    cout << s << '\n';

    return 0;
}