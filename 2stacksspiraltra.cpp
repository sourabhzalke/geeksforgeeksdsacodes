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
void bfs(Node* root){
    if(root==NULL)
        return;
    stack<Node*> s1;
    stack<Node*> s2;
    s1.push(root);
    bool rs=false;
    while(!s1.empty() || !s2.empty()){
        if(!rs){
        Node* x = s1.top();
        s1.pop();
        cout<<x->data<<" ";
        //if not reverse push elements in s2 cause we can pop in reverse from it
        if(x->left!=NULL)
            s2.push(x->left);
        if(x->right!=NULL)
            s2.push(x->right);
        if(s1.empty())
            rs=!rs;
        }else{
            Node* x = s2.top();
            s2.pop();
            cout<<x->data<<" ";
            //if reverse push nodes in s1 vice versa
            if(x->right!=NULL)
                s1.push(x->right);
            if(x->left!=NULL)
                s1.push(x->left);
            if(s2.empty()){
                rs=!rs;
            }
        }
    }
}

void bfs1(Node* root){
    if(root==NULL)
        return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* x = q.front();
        q.pop();
        cout<<x->data<<" ";
        if(x->left!=NULL)
            q.push(x->left);
        if(x->right!=NULL)
            q.push(x->right);
    }
}

int main(){ 
    Node *root = new Node(1);
    insertn(root,2,0);
    insertn(root,3,1);
    insertn(root->left,4,0);
    insertn(root->left,5,1);
    insertn(root->right,6,0);
    insertn(root->right,7,1);
    insertn(root->left->left,8,0);
    insertn(root->left->left,9,1);
    insertn(root->right->left,10,0);
    bfs1(root);
    cout<<"\n";
    bfs(root);
}
