#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

const double INF = numeric_limits<double>::infinity();

struct Point{
    int x, y;
    Point() { x = y = 0; }
    Point(int x, int y) : x(x), y(y) {}
    bool operator==(const Point& other){
        return (x == other.x && y == other.y);
    }
};

istream& operator>>(istream& s, Point& p){
    s >> p.x >> p.y;
    return s;
}

ostream& operator<<(ostream& s, Point& p){
    s << (double)p.x << ' ' << (double)p.y;
    return s;
}

enum class Ornt {pos, col, neg};

int crossProduct(int x1, int y1, int x2, int y2){
    return (x1*y2 - x2*y1);
}

Ornt orientation(const Point& p1, const Point& p2, const Point& p3){
    int d = crossProduct(p3.x-p1.x, p3.y-p1.y, p3.x-p2.x, p3.y-p2.y);
    if(d > 0) return Ornt::pos;
    else if(d < 0) return Ornt::neg;
    return Ornt::col;
}

int main()
{
    Point a, b, c, d;
    cin >> a >> b >> c >> d;

    cout << fixed << setprecision(5);

    if(crossProduct(b.x-a.x, b.y-a.y, d.x-c.x, d.y-c.y) == 0){
        if(a.x <= c.x && b.x >= c.x && a.y <= c.y && b.y >= c.y){
            cout << "da\n";
            if(a == c || b == c)
                cout << c << '\n';
        } else if(a.x <= d.x && b.x >= d.x && a.y <= d.y && b.y >= d.y)
        {
            cout << "da\n";
            if(a == d || b == d)
                cout << d << '\n';
        }
        else cout << "ne\n";
    }else if(
        orientation(a, b, c) == orientation(a, b, d) ||
        orientation(c, d, a) == orientation(c, d, b)
        )
    {
        cout << "ne\n";
    } else {
        cout << "da\n";
        double k1 = 1.0 * (b.y - a.y) / (b.x - a.x),
            k2 = 1.0 * (d.y - c.y) / (d.x - c.x);
        if(a.x == b.x)
            cout << (double)a.x << ' ' << k2 * (a.x - c.x) + c.y << '\n';
        else if(d.x == c.x)
            cout << (double)c.x << ' ' << k1 * (c.x - a.x) + a.y << '\n';
        else {
            double x = (c.y - a.y + k1*a.x - k2*c.x) / (k1 - k2);
            double y = k1 * (x - a.x) + a.y;
            cout << x << ' ' << y << '\n';
        }
    }

    return 0;
}