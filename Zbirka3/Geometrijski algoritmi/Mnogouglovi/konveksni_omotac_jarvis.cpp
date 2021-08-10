// Jarvis' march

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

vector<Point> convexHull(int n, const vector<Point>& arr){
    vector<Point> hull(1, arr[0]);
    for(int i=1; i<n; i++){
        if(arr[i].x < hull[0].x)
            hull[0] = arr[i];
        else if(arr[i].x == hull[0].x && arr[i].y < hull[0].y)
            hull[0] = arr[i];
    }

    Point p = hull[0];
    do{
        Point q = arr[0];
        for(int i=0; i<n; i++){
            Ornt o = orientation(p, q, arr[i]);
            if(o == Ornt::Neg)
                q = arr[i];
            else if(o == Ornt::Cln && dist(p, arr[i]) > dist(p, q))
                q = arr[i];
        }
        hull.push_back(q);
        p = q;

    } while(p != hull[0]);
    
    hull.pop_back();

    return hull;
}

int main()
{
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