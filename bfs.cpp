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

void bfs(Node* root){
    if(root==NULL)
        return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node *x = q.front();
        q.pop();
        cout<<x->data<<" ";
        if(x->left!=NULL)
        q.push(x->left);
        if(x->right!=NULL)
        q.push(x->right);
    }
}
int main(){
    Node *root = new Node(10);
    root->right = new Node(6);
    root->right->left = new Node(2);
    root->right->right = new Node(4);
    root->right->right->left = new Node(3);
    bfs(root);
}
