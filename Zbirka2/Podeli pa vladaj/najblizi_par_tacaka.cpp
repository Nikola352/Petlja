#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point{
    int x, y;
};

bool compX(const Point& p1, const Point& p2){
    return (p1.x < p2.x);
}

double dist(const Point& p1, const Point& p2){
    double x2 = ((double)p1.x - (double)p2.x) * ((double)p1.x - (double)p2.x);
    double y2 = ((double)p1.y - (double)p2.y) * ((double)p1.y - (double)p2.y);
    return sqrt(x2 + y2);
}

const double INF = numeric_limits<double>::infinity();

double solve(vector<Point>& arr, int l, int r){
    if(l == r) return INF;

    int m = l + (r-l)/2;
    Point mp = arr[m];

    double d1 = solve(arr, l, m),
        d2 = solve(arr, m+1, r);

    vector<Point> rarr;
    int i=l, j=m+1;
    while(i <= m && j <= r){
        if(arr[i].y <= arr[j].y)
            rarr.push_back(arr[i++]);
        else
            rarr.push_back(arr[j++]);
    }

    while(i <= m) rarr.push_back(arr[i++]);
    while(j <= r) rarr.push_back(arr[j++]);

    for(int i=l; i<=r; i++)
        arr[i] = rarr[i-l];

    double d = min(d1, d2);

    vector<Point> strip;
    for(int i=l; i<=r; i++)
        if((double)abs(arr[i].x-mp.x) < d)
            strip.push_back(arr[i]);

    for(int i=0; i<strip.size(); i++){
        // unutrasnja petlja se izvrsava najvise 7 puta?
        for(int j=i+1; j<strip.size() && strip[j].y-strip[i].y < d; j++)
            d = min(d, dist(strip[i], strip[j]));
    }

    return d;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<Point> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i].x >> arr[i].y;

    sort(arr.begin(), arr.end(), compX);

    cout << fixed << setprecision(5) << solve(arr, 0, n-1) << '\n';

    return 0;
}