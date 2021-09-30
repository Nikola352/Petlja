// Graham Scan

#include <bits/stdc++.h>
using namespace std;

struct Point{
    int x, y;
    Point() {}
    Point(int x, int y) : x(x), y(y) {}
    bool operator==(const Point& other){
        return (x == other.x && y == other.y);
    }
    bool operator!=(const Point& other){
        return !(*this == other);
    }
};

istream& operator>>(istream& s, Point& p){
    s >> p.x >> p.y;
    return s;
}

ostream& operator<<(ostream& s, const Point& p){
    s << p.x << ' ' << p.y << '\n';
    return s;
} 

int dist(const Point& p1, const Point& p2){
    return ((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

enum class Ornt {Neg, Pos, Cln};

Ornt orientation(const Point& p1, const Point& p2, const Point& p3){
    // (p3.x-p1.x, p3.y-p1.y) x (p3.x-p2.x, p3.y-p2.y)
    int d = (p3.x-p1.x)*(p3.y-p2.y) - (p3.x-p2.x)*(p3.y-p1.y);
    if(d < 0) return Ornt::Neg;
    if(d > 0) return Ornt::Pos;
    return Ornt::Cln;
}

Point xp;

bool comp(const Point& p1, const Point& p2){
    Ornt o = orientation(xp, p1, p2);
    if(o == Ornt::Cln)
        return (dist(xp, p1) > dist(xp, p2));
    return (o == Ornt::Neg);
}

vector<Point> convexHull(int n, vector<Point>& arr){
    for(int i=1; i<n; i++){
        if(arr[i].x < arr[0].x)
            swap(arr[i], arr[0]);
        else if(arr[i].x == arr[0].x && arr[i].y < arr[0].y)
            swap(arr[i], arr[0]);
    }

    xp = arr[0]; 
    sort(next(arr.begin()), arr.end(), comp);

    vector<Point> hull;
    hull.push_back(arr[0]);
    hull.push_back(arr[1]);

    for(int i=2; i<n; i++){
        if(orientation(xp, arr[i], arr[i-1]) == Ornt::Cln)
            continue;
        while(orientation(hull[hull.size()-2], hull[hull.size()-1], arr[i]) != Ornt::Neg)
            hull.pop_back();
        hull.push_back(arr[i]);
    }

    return hull;
}

int main()
{
    cin.tie(0);

    int n;
    cin >> n;
    vector<Point> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];

    vector<Point> hull = convexHull(n, arr);

    cout << hull.size() << '\n';
    for(Point p : hull)
        cout << p;

    return 0;
}
