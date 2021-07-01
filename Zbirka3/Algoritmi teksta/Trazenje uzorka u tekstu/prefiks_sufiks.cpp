#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int n;
    cin >> n;

    int l=str.length(), len=0, i=1;
    vector<int> dp(l);
    dp[0] = 0;
    while(i < l){
        if(str[i] == str[len])
            dp[i++] = ++len;
        else if(len>0)
            len = dp[len-1];
        else
            dp[i++] = 0;
    }

    cout << n*l - (n-1)*dp[l-1];

    return 0;
}