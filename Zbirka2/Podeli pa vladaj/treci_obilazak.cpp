#include <iostream>
#include <vector>
using namespace std;

struct Node{
    char val;
    Node *left, *right;
    Node(char val) : val(val){
        left = right = NULL;
    }
};

Node* buildTree(const string& preorder, const string& inorder, int n, int l, int r){
    static int pi = 0;
    if(pi == n || l > r) return NULL;

    char curr = preorder[pi++];

    Node* node = new Node(curr);

    int ii=-1;
    for(int i=l; i<=r; i++){
        if(inorder[i] == curr){
            ii = i;  break;
        }
    }

    node->left = buildTree(preorder, inorder, n, l, ii-1);
    node->right = buildTree(preorder, inorder, n, ii+1, r);

    return node;
}

void postorder(Node* root){
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val;
}

int main()
{
    string preorder, inorder;
    cin >> preorder >> inorder;

    int n = preorder.size();

    Node* root = buildTree(preorder, inorder, n, 0, n-1);

    postorder(root);
    cout << endl;

    return 0;
}