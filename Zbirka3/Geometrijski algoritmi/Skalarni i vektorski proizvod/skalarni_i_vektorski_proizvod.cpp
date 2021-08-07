#include <iostream>
using namespace std;

int main()
{
    int x1, y1, z1, x2, y2, z2;
    cin >> x1 >> y1 >> z1
        >> x2 >> y2 >> z2;

    if(y1*z2 == y2*z1 && z1*x2 == z2*x1 && x1*y2 == x2*y1)
        cout << "kolinearni\n";
    else if(x1*x2 + y1*y2 + z1*z2 == 0)
        cout << "normalni\n";
    else cout << "-\n";

    return 0;
}