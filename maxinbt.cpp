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

int maxinbt(Node* root){
    if(root==NULL)
        return INT_MIN;
    return max(root->data,max(maxinbt(root->left),maxinbt(root->right)));
}

int main(){
    Node *root = new Node(10);
    root->left = new Node(30);
    root->right = new Node(40);
    root->left->left = new Node(80);
    root->left->left->right = new Node(70);
    root->right->left = new Node(60);
    root->right->right = new Node(20);
    int x = maxinbt(root);
    cout<<"Maximum in Binary Tree is:"<<x;
}
