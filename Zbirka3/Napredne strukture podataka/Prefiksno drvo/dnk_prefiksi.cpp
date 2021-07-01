#include <iostream>
using namespace std;

int chToIdx(char ch){
    switch (ch) {
    case 'a':
        return 0;
    case 'c':
        return 1;
    case 't':
        return 2;
    case 'g':
        return 3;
    }
    return -1;
}

struct Node{
    int leafs;
    Node* children[4];
    Node(){
        leafs = 0;
        for(int i=0; i<4; i++)
            children[i] = nullptr;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node* root = new Node();

    string dnk;
    while(cin >> dnk){
        int n = dnk.length();
        Node* node = root;
        for(int i=0; i<n; i++){
            node->leafs++;
            int idx = chToIdx(dnk[i]);
            if(node->children[idx] == nullptr)
                node->children[idx] = new Node();
            node = node->children[idx];
        }
        cout << node->leafs << '\n';
        node->leafs++;
    }

    return 0;
}