#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
    
    Node(int val){
    data = val;
    left = NULL;
    right = NULL;
    }
};

void printK(Node* root,int k){
    if(root==NULL || k==-1)
        return;
    k--;
    if(k==-1)
        cout<<root->data<<" ";
    printK(root->left,k);
    printK(root->right,k);
}

int main(){
    //creating the tree
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->right = new Node(70);
    printK(root,2);
}
