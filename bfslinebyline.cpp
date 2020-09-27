#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

void linebfs(Node* root){
    if(root==NULL)
        return;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(q.size()>1){
        Node* x = q.front();
        q.pop();
        if(x==NULL){
            q.push(NULL);
            cout<<"\n";
        }else{
        cout<<x->data<<" ";
        if(x->left!=NULL)
            q.push(x->left);
        if(x->right!=NULL)
            q.push(x->right);
        }
    }
}
int main(){
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->right = new Node(60);
    root->right->right->left = new Node(70);
    root->right->right->right = new Node(80);
    linebfs(root);
}
