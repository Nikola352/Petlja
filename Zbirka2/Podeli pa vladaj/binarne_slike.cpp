#include <iostream>
#include <vector>
using namespace std;

vector<int> getStart(const string& img, int l, int r){
    vector<int> res(4);
    int depth=0, ri=0;
    for(int i=l+1; i<r; i++){
        if(depth == 0) res[ri++] = i;
        if(img[i] == '[') depth++;
        else if(img[i] == ']') depth--;
    }
    return res;
}

string solve(const string& img1, const string& img2, int l1, int r1, int l2, int r2, char pc){
    if(l1 == r1){
        if(img1[l1] == pc) 
            return string(1, pc);
        return img2.substr(l2, r2-l2+1);
    }
    if(l2 == r2){
        if(img2[l2] == pc)
            return string(1, pc);
        return img1.substr(l1, r1-l1+1);
    }

    vector<int> s1 = getStart(img1, l1, r1);
    vector<int> s2 = getStart(img2, l2, r2);

    string p1 = solve(img1, img2, s1[0], s1[1]-1, s2[0], s2[1]-1, pc),
        p2 = solve(img1, img2, s1[1], s1[2]-1, s2[1], s2[2]-1, pc),
        p3 = solve(img1, img2, s1[2], s1[3]-1, s2[2], s2[3]-1, pc),
        p4 = solve(img1, img2, s1[3], r1-1, s2[3], r2-1, pc);

    if(p1 == p2 && p2 == p3 && p3 == p4){
        if(p1 == "1") return "1";
        else if(p1 == "0") return "0";
    }

    return ("[" + p1 + p2 + p3 + p4 + "]");
}

int main()
{
    string img1, img2;
    cin >> img1 >> img2;

    cout << solve(img1, img2, 0, img1.size()-1, 0, img2.size()-1, '1') << '\n';
    cout << solve(img1, img2, 0, img1.size()-1, 0, img2.size()-1, '0') << '\n';

    return 0;
}