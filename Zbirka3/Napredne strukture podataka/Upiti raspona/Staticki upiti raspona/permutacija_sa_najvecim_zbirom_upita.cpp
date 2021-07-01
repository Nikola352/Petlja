#include <bits/stdc++.h>
using namespace std;

bool compSegCount(const pair<int, int>& a, const pair<int, int>& b){
    return (a.first > b.first);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> lamps(n);
    for(int i=0; i<n; i++)
        cin >> lamps[i];

    int s;
    cin >> s;
    vector<int> diff(n+1, 0);
    for(int i=0; i<s; i++){
        int l, r;
        cin >> l >> r;
        l--; r--;
        diff[l]++;
        diff[r+1]--;
    }

    vector<int> segCount(n);
    int currSegCount = 0;
    for(int i=0; i<n; i++){
        currSegCount += diff[i];
        segCount[i] = currSegCount;
    }

    sort(lamps.begin(), lamps.end(), greater<int>());
    sort(segCount.begin(), segCount.end(), greater<int>());

    int64_t sum = 0;
    for(int i=0; i<n; i++)
        sum += ((int64_t)segCount[i]) * lamps[i];

    cout << sum << '\n';

    return 0;
}