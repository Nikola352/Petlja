#include <iostream>
using namespace std;

int main()
{
    unsigned int brSlogova, brDece, prvoDete;
    cin >> brSlogova >> brDece >> prvoDete;

    cout << ((prvoDete + brSlogova - 1) % brDece) << endl;

    return 0;
}