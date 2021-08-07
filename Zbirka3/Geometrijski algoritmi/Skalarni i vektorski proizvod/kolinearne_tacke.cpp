#include <iostream>
using namespace std;

int crossProduct(int x1, int y1, int x2, int y2){
    return (x1*y2 - x2*y1);
}

int main()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int n, c=0;
    cin >> n;
    while(n--){
        int x, y;
        cin >> x >> y;
        if(crossProduct(x-x1, y-y1, x-x2, y-y2) == 0)
            c++;
    }

    cout << c << '\n';

    return 0;
}