#include <iostream>
using namespace std;

int main()
{
    unsigned int n, a, b;
    cin >> n >> a >> b;

    a %= n;
    b %= n;

    cout << ((b - a + n) % n) << endl;

    return 0;
}