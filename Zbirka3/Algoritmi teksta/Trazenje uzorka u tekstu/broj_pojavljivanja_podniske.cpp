#include <bits/stdc++.h>
using namespace std;

vector<int> constructLps(string pat, int n){
    vector<int> lps(n);
    lps[0] = 0;
    int i=1, j=0;
    while(i < n){
        if(pat[i] == pat[j])
            lps[i++] = ++j;
        else if(j > 0)
            j = lps[j-1];
        else
            lps[i++] = 0;
    }
    return lps;
}

int count(string pat, string str){
    int n = str.length(),
        m = pat.length();

    vector<int> lps = constructLps(pat, m);

    int c=0, i=0, j=0;
    while(i < n){
        if(j == m){
            c++;
            j = lps[j-1];
        } else if(str[i] == pat[j]){
            i++;
            j++;
        } else if(j>0){
            j = lps[j-1];
        } else {
            i++;
        }
    }

    if(j==m) c++;

    return c;
}

int main()
{
    string pat, str;
    cin >> pat >> str;

    cout << count(pat, str) << '\n';

    return 0;
}