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
int ipre = 0;
Node* btwithot(int in[],int pre[],int is,int ie){
    if(is>ie)
        return NULL;
    Node *root = new Node(pre[ipre++]);
    int index;
    for(int i=is;i<=ie;++i){
        if(root->data==in[i]){
            index=i;
            break;
        }
    }
    root->left= btwithot(in,pre,is,index-1);
    root->right= btwithot(in,pre,index+1,ie);
    return root;
}

int main(){
        int in[]={20,10,40,30,50};
        int pre[]={10,20,30,40,50};
        Node* root =  btwithot(in,pre,0,4);
        bfs(root);
}
