#include <bits/stdc++.h>
using namespace std;

int chToIdx(char ch){
    return (ch - 'a');
}

struct Node{
    Node* children[4];
    Node(){
        for(int i=0; i<4; i++)
            children[i] = nullptr;
    }
};

void insert(Node* root, const string& str, int n, int i){
    while(i < n){
        int idx = chToIdx(str[i]);
        if(root->children[idx] == nullptr)
            root->children[idx] = new Node();
        root = root->children[idx];
        i++;
    }
}

int countNodes(Node* root){
    stack<Node*> st;
    st.push(root);
    int c = 0;
    while(!st.empty()){
        Node* node = st.top();
        st.pop();
        c++;
        for(int i=0; i<4; i++){
            if(node->children[i])
                st.push(node->children[i]);
        }
    }
    return c;
}

int main()
{
    string str;
    cin >> str;

    int n = str.length();

    Node* root = new Node();

    for(int i=0; i<n; i++){
        insert(root, str, n, i);
    }

    cout << countNodes(root) << '\n';

    return 0;
}