#include <iostream>
using namespace std;

typedef uint64_t ull;

struct Node{
    Node* children[2];
    Node(){
        children[0] = children[1] = nullptr;
    }
};

void insert(Node* root, ull n){
    for(int i=63; i>=0; i--){
        if(!root->children[(n>>i)&1])
            root->children[(n>>i)&1] = new Node();
        root = root->children[(n>>i)&1];
    }
}

int main()
{
    int n;
    cin >> n;

    Node* root = new Node();

    ull max = 0;

    ull br;
    cin >> br;

    insert(root, br);

    for(int i=1; i<n; i++){
        cin >> br;
        ull mask = 0;
        Node* node = root;
        for(int i=63; i>=0; i--){
            if(node->children[!((br>>i)&1)]){
                mask = mask | (1ull<<i);
                node = node->children[!((br>>i)&1)];
            } else {
                node = node->children[(br>>i)&1];
            }
        }
        if(mask > max) max = mask;
        insert(root, br);
    }

    cout << max << '\n';

    return 0;
}