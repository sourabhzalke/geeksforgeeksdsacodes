#include<bits/stdc++.h>
#define lli long long int
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int val){
        data  = val;
        left = NULL;
        right = NULL;
    }
};

bool childrensum(Node* root){
    if(root==NULL)
        return true;
    if(root->left==NULL && root->right==NULL)
        return true;
    int sum =0;
    if(root->left!=NULL)
        sum += root->left->data;
    if(root->right!=NULL)
        sum += root->right->data;
    return (root->data==sum && childrensum(root->left) && childrensum(root->right));
}


int main(){
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(12);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    bool ans = childrensum(root);
//    printbt(root);
    cout<<ans;
}

