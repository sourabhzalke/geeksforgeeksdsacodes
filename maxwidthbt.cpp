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

void insertn(Node* parent,int data,int side){
    if(side==0)
        parent->left = new Node(data);
    else
        parent->right = new Node(data);
}

int maxwidth(Node* root){
    if(root==NULL)
        return 0;
    queue<Node*> q;
    q.push(root);
    int s = 1;
    while(!q.empty()){
        Node* x = q.front();
        q.pop();
        cout<<x->data<<" ";
        if(x->left!=NULL)
            q.push(x->left);
        if(x->right!=NULL)
            q.push(x->right);
        s = max(s,int(q.size()));
    }
    return s;
}

int main(){
    Node* root = new Node(3);
    insertn(root,40,0);
    insertn(root,5,1);
    insertn(root->left,4,0);
    insertn(root->left,4,1);
    insertn(root->right,70,1);
    //insertn(root->right,13,0);
    //insertn(root->left->right,10,1);
    //insertn(root->right,5,0);
    int x =maxwidth(root);
    cout<<"Maximum width of Binary Tree:"<<x<<endl;
}
