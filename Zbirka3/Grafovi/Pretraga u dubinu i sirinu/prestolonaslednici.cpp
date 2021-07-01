#include <bits/stdc++.h>
using namespace std;

void inorder(string v, unordered_map<string, vector<string>>& adj, unordered_map<string, int>& result, int& res){
    result[v] = res;
    for(auto it=adj[v].begin(); it!=adj[v].end(); it++){
        inorder(*it, adj, result, ++res);
    }
}

int main()
{
    int n;
    cin >> n;
    unordered_map<string, vector<string>> adj;
    unordered_map<string, int> result;
    unordered_set<string> children;
    for(int i=1; i<n; i++){
        string parent, child;
        cin >> parent >> child;
        adj[parent].push_back(child);
        children.insert(child);
    }

    string king;
    for(auto& it : adj){
        if(children.find(it.first) == children.end()){
            king = it.first;
            break;
        }
    }

    int res = 0;
    inorder(king, adj, result, res);

    string name;
    while(cin >> name){
        cout << name << ' ' << result[name] << '\n';
    }

    return 0;
}