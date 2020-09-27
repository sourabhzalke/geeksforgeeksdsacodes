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
//using one variable checking if reverse or not
bool rs=false;
void bfs(Node* root){
    if(root==NULL)
        return;
    queue<Node*> q;
    q.push(root);
    stack<int> s;
    while(!q.empty()){
        int count = q.size();
        //its level order traversal
        //1). for printing left to right direction nodes
        for(int i=0;i<count;++i){
        Node* x = q.front();
        q.pop();
        if(rs){
            //if reverse push into stack
            s.push(x->data);
        }
        else{
        //if not reverse print elements from queue
        cout<<x->data<<" ";
        }
        //push all elements into the queue, it has redundancy for rs nodes, Solution use 2 stacks
        if(x->left!=NULL)
            q.push(x->left);
        if(x->right!=NULL)
            q.push(x->right);
        }
        //2). for printing right to left nodes
        if(rs){
            while(!s.empty()){
                cout<<s.top()<<" ";
                s.pop();
            }
        }
        rs=!rs;
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
    bfs(root);
}
