// KMP
#include <bits/stdc++.h>
using namespace std;

vector<int> constructLps(string pat, int m){
    vector<int> lps(m);
    lps[0] = 0;
    int i=1, j=0;
    while(i < m){
        if(pat[i] == pat[j])
            lps[i++] = ++j;
        else if(j > 0)
            j = lps[j-1];
        else
            lps[i++] = 0;
    }
    return lps;
}

int search(string pat, string str){
    int n = str.length(),
        m = pat.length();

    vector<int> lps = constructLps(pat, m);
    
    int i=0, j=0;
    while(i < n){
        if(j == m){
            return i-m;
        } else if(str[i] == pat[j]){
            i++;
            j++;
        } else if(j > 0){
            j = lps[j-1];
        } else {
            i++;
        }
    }

    if(j == m)
        return n-m;
    return -1;
}

int main()
{
    string str, pat;
    cin >> str >> pat;

    cout << search(pat, str) << '\n';

    return 0;
}