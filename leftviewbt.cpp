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
int maxlevel = 0;
void leftview(Node* root,int level){
    if(root==NULL)
        return;
    if(maxlevel<level){
        cout<<root->data<<" ";
        maxlevel=level;
    }
    leftview(root->left,level+1);
    leftview(root->right,level+1);
}

int main(){
    Node *root = new Node(30);
    //root->left = new Node(20);
    //root->left->left= new Node(40);
    //root->left->right = new Node(50);
    root->right = new Node(50);
    root->right->left = new Node(60);
    root->right->left->right = new Node(10);
    leftview(root,1);
}
