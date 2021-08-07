#include <iostream>
using namespace std;

enum Orientation {Positive, Colinear, Negative};

int crossProduct(int x1, int y1, int x2, int y2){
    return (x1*y2 - x2*y1);
}

Orientation orientation(int x1, int y1, int x2, int y2, int x3, int y3){
    int d = crossProduct(x3-x1, y3-y1, x3-x2, y3-y2);
    if(d > 0) return Positive;
    if(d < 0) return Negative;
    return Colinear;
}

int main()
{
    int xa, ya, xb, yb, xt, yt;
    cin >> xa >> ya >> xb >> yb >> xt >> yt;

    int n, c=0;
    cin >> n;
    while(n--){
        int x, y;
        cin >> x >> y;
        if(orientation(xa,ya,xb,yb,xt,yt) == orientation(xa,ya,xb,yb,x,y))
            c++;
    }

    cout << c << '\n';

    return 0;
}