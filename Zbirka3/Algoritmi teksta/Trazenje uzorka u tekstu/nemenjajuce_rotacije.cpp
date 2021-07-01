#include <bits/stdc++.h>
using namespace std;

vector<int> makeLps(const string& str, int n){
    vector<int> lps(n, 0);
    lps[0] = 0;
    int i=1, j=0;
    while(i < n){
        if(str[i] == str[j])
            lps[i++] = ++j;
        else if(j == 0)
            lps[i++] = 0;
        else
            j = lps[j-1];
    }
    return lps;
}

int count(string pat, string str){
    int n = str.length(), m = pat.length();

    vector<int> lps = makeLps(pat, m);
    
    int i=0, j=0, c=0;;
    while(i < n){
        if(j == m){
            c++;
            j = lps[j-1];
        }
        if(str[i] == pat[j]){
            i++; j++;
        } else if(j==0){
            i++;
        } else{
            j = lps[j-1];
        }
    }

    if(j == m) c++;
    return c;
}

int main()
{
    string str;
    cin >> str;
    string twice = str + str;

    cout << count(str, twice)-1 << '\n';

    return 0;
}