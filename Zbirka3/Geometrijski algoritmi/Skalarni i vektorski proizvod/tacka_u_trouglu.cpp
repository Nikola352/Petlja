#include <iostream>
#include <cmath>
using namespace std;

const double eps = 1e-9;

double crossProduct(double x1, double y1, double x2, double y2){
    return (x1*y2 - x2*y1);
}

int main()
{
    double x, y, xa, ya, xb, yb, xc, yc;
    cin >> x >> y >> xa >> ya >> xb >> yb >> xc >> yc;

    if(
        abs(crossProduct(xb-xa, yb-ya, x-xa, y-ya)) +
        abs(crossProduct(x-xb, y-yb, x-xc, y-yc)) +
        abs(crossProduct(xa-xc, ya-yc, x-xa, y-ya)) -
        abs(crossProduct(xb-xa, yb-ya, xc-xa, yc-ya))
        < eps
        ) cout << "da\n";
    else cout << "ne\n";

    return 0;
}