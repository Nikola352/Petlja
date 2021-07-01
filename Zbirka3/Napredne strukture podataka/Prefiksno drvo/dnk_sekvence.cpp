#include <bits/stdc++.h>
using namespace std;

int chToIdx(char ch){
    if(ch == 'c') return 0;
    if(ch == 't') return 1;
    if(ch == 'g') return 2;
    if(ch == 'a') return 3;
    return -1;
}

struct Node{
    Node* children[4];
    bool isLeaf;
    Node(){
        for(int i=0; i<4; i++)
            children[i] = NULL;
        isLeaf = false;
    }
};

bool find(Node* root, const string& str){
    if(!root) return false;
    int strlen = str.length();
    for(int i=0; i<strlen; i++){
        int idx = chToIdx(str[i]);
        if(root->children[idx] == NULL)
            return false;
        root = root->children[idx];
    }
    return (root->isLeaf);
}

void insert(Node* root, const string& str){
    int strlen = str.length();
    for(int i=0; i<strlen; i++){
        int idx = chToIdx(str[i]);
        if(root->children[idx] == NULL)
            root->children[idx] = new Node();
        root = root->children[idx];
    }
    root->isLeaf = true;
}

bool isEmpty(Node* root){
    for(int i=0; i<4; i++){
        if(root->children[i])
            return false;
    }
    return true;
}

Node* remove(Node* root, const string& str, int idx=0){
    if(!root) return NULL;

    if(idx == str.length()){
        root->isLeaf = false;
        if(isEmpty(root)){
            delete root;
            root = NULL;
        }
        return root;
    }

    int index = chToIdx(str[idx]);

    root->children[index] = remove(root->children[index], str, idx+1);

    if(idx!=0 && isEmpty(root) && !root->isLeaf){
        delete root;
        root = NULL;
    }

    return root;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    Node* root = new Node();

    for(int i=0; i<n; i++){
        string query, str;
        cin >> query >> str;
        if(query == "ubaci"){
            insert(root, str);
        } else if(query == "izbaci"){
            root = remove(root, str);
        } else if(query == "trazi") {
            cout << (find(root, str) ? "da\n" : "ne\n");
        }
    }

    delete root;

    return 0;
}