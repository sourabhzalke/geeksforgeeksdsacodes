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

int checkbaltree(Node* root){
    if(root==NULL)
        return 0;
    int lh = checkbaltree(root->left);
    if(lh==-1)
        return -1;
    int rh = checkbaltree(root->right);
    if(rh==-1)
        return -1;
    if(abs(lh-rh)>1)
        return -1;
    else
        return max(lh,rh)+1;
}

int main(){
    Node* root = new Node(3);
    //insertn(root,40,0);
    insertn(root,5,0);
    insertn(root->left,4,0);
    //insertn(root->right,70,1);
    //insertn(root->right,13,0);
    //insertn(root->left->right,10,1);
    //insertn(root->right,5,0);
    int x =checkbaltree(root);
    if(x==-1)
    cout<<"Balance Tree check: False"<<endl;
    else
    cout<<"Balance Tree check: True"<<endl;
}
