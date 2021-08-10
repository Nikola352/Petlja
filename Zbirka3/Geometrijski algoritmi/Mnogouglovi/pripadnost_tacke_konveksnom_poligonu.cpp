#include <bits/stdc++.h>
using namespace std;

struct Point{
    int x, y;
};

istream& operator>>(istream& is, Point& point){
    is >> point.x >> point.y;
    return is;
}

enum class Orientation {Positive, Negative, Colinear};

Orientation orientation(const Point& p1, const Point& p2, const Point& p3){
    int d = (p3.x - p1.x) * (p3.y - p2.y) - (p3.x - p2.x) * (p3.y - p1.y);
    if(d < 0) return Orientation::Negative;
    if(d > 0) return Orientation::Positive;
    return Orientation::Colinear;
}

bool insideTriangle(const Point& a, const Point& b, const Point& c, const Point& p){
    Orientation o3 = orientation(a, b, p);
    Orientation o2 = orientation(b, c, p);
    Orientation o1 = orientation(c, a, p);
    if(o1 == o2 && o2 == o3)
        return true;
    if(o1 == Orientation::Colinear)
        return (o2 == o3 || o2 == Orientation::Colinear || o3 == Orientation::Colinear);
    if(o2 == Orientation::Colinear)
        return (o1 == o3 || o1 == Orientation::Colinear || o3 == Orientation::Colinear);
    if(o3 == Orientation::Colinear)
        return (o1 == o2 || o1 == Orientation::Colinear || o2 == Orientation::Colinear);
    return false;
}

bool insidePolygon(const vector<Point>& arr, int n, const Point& p){
    int l=1, r=n-2, lp=-1;
    while(l <= r){
        int mid = l + (r-l)/2;
        Orientation ornt = orientation(arr[0], arr[mid], p);
        if(ornt == Orientation::Positive || ornt == Orientation::Colinear){
            lp = mid;
            l = mid + 1;
        }
        else if(ornt == Orientation::Negative)
            r = mid - 1;
    }
    if(lp == -1) 
        return false;
    return insideTriangle(arr[0], arr[lp], arr[lp+1], p);
}

int main()
{
    int n;
    cin >> n;
    vector<Point> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];

    int m;
    cin >> m;
    while(m--){
        Point p;
        cin >> p;
        cout << (insidePolygon(arr, n, p) ? "da\n" : "ne\n");
    }

    return 0;
}