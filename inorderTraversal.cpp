#include <bits/stdc++.h>
#define lli long long int
using namespace std;
struct Node{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
void inorder(Node* root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<"-->";
    inorder(root->right);
}
int main(){
        Node* root = new Node(10);
        root->left = new Node(20);
        root->right = new Node(30);
        root->right->right = new Node(50);
        root->right->left = new Node(40);
        inorder(root);
}
