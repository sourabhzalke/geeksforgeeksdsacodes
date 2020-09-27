#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
    data = val;
    left = NULL;
    right = NULL;
    }
};

int sizeofBT(Node* root){
    if(root==NULL)
        return 0;
    return sizeofBT(root->left)+sizeofBT(root->right)+1;
}

int main(){
    Node *root = new Node(10);
    root->left = new Node(80);
    root->right = new Node(70);
    root->left->left = new Node(30);
    int ans = sizeofBT(root);
    cout<<ans;
}
