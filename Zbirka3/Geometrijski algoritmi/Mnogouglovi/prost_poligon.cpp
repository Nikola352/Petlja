#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-8;

struct Point{
    int x, y;
    Point() {}
    Point(int x, int y) : x(x), y(y) {}
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

bool colinear(const Point& p1, const Point& p2, const Point& p3){
    return (orientation(p1, p2, p3) == Ornt::Cln);
}

Point xp;

bool comp(const Point& p1, const Point& p2){
    Ornt ornt = orientation(p1, p2, xp);
    if(ornt == Ornt::Cln)
        return (dist(p1, xp) < dist(p2, xp));
    return (ornt == Ornt::Pos);
}

void simplePolygon(int n, vector<Point>& arr){
    int exti = 0;
    for(int i=0; i<n; i++){
        if(arr[i].x > arr[exti].x)
            exti = i;
        else if(arr[i].x == arr[exti].x && arr[i].y < arr[exti].y)
            exti = i;
    }

    swap(arr[0], arr[exti]);
    xp = arr[0];

    sort(++arr.begin(), arr.end(), comp);

    stack<Point> st;
    int li = n-1;
    for(int i=n-1; i>1 && colinear(arr[i], arr[i-1], xp); i--){
        st.push(arr[i]);
        li = i-1;
    }
    swap(arr[li], arr[n-1]);
    for(int i=li; i<n-1; i++){
        arr[i] = st.top();
        st.pop();
    }
}

int main()
{
    int n;
    cin >> n;
    vector<Point> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];

    simplePolygon(n, arr);

    for(int i=0; i<n; i++)
        cout << arr[i];

    return 0;
}