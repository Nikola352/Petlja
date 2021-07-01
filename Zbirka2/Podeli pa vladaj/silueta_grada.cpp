#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Building{
    int left, right, h;
};

typedef pair<int, int> pii;
typedef vector<pii> vii;

vii getSkyline(const vector<Building>& arr, int l, int r){
    if(l == r){
        vii res;
        res.push_back(pii(arr[l].left, arr[l].h));
        res.push_back(pii(arr[l].right, 0));
        return res;
    } 

    int m = l + (r-l)/2;

    vii s1 = getSkyline(arr, l, m),
        s2 = getSkyline(arr, m+1, r);

    int n1=s1.size(), n2=s2.size();

    vii res; int i = -1;

    int i1=0, i2=0, ch1=0, ch2=0;
    while(i1 < n1 && i2 < n2){
        if(s1[i1].first < s2[i2].first){
            ch1 = s1[i1].second;
            int ch = max(ch1, ch2);
            if(res.empty() || ch != res[i].second){
                res.push_back(pii(s1[i1].first, ch));
                i++;
            }
            i1++;
        } else if(s2[i2].first < s1[i1].first) {
            ch2 = s2[i2].second;
            int ch = max(ch1, ch2);
            if(res.empty() || ch != res[i].second){
                res.push_back(pii(s2[i2].first, ch));
                i++;
            }
            i2++;
        } else {
            ch1 = s1[i1].second;
            ch2 = s2[i2].second;
            int ch = max(ch1, ch2);
            if(res.empty() || ch != res[i].second){
                res.push_back(pii(s1[i1].first, ch));
                i++;
            }
            i1++; i2++;
        }
    }

    while(i1 < n1){
        ch1 = s1[i1].second;
        int ch = max(ch1, ch2);
        if(res.empty() || ch != res[i].second){
            res.push_back(pii(s1[i1].first, ch));
            i++;
        }
        i1++;
    }

    while(i2 < n2){
        ch2 = s2[i2].second;
        int ch = max(ch1, ch2);
        if(res.empty() || ch != res[i].second){
            res.push_back(pii(s2[i2].first, ch));
            i++;
        }
        i2++;
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<Building> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i].left >> arr[i].right >> arr[i].h;

    vii skyline = getSkyline(arr, 0, n-1);

    for(int i=0; i<skyline.size(); i++)
        cout << skyline[i].first << ' ' << skyline[i].second << '\n';

    return 0;
}