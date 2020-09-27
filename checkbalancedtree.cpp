#include<bits/stdc++.h>
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

int height(Node* root){
    if(root==NULL)
        return 0;
    return max(height(root->left),height(root->right))+1;
}

bool checkbaltree(Node* root){
    if(root==NULL)
        return true;
    int heightL=0,heightR=0;
    if(root->left!=NULL)
        heightL=height(root->left);
    if(root->right!=NULL)
        heightR= height(root->right);
    return ((abs(heightL-heightR)<=1) && checkbaltree(root->left) && checkbaltree(root->right));
}

void insertn(Node* parent,int data,int side){
    if(side==0)
        parent->left = new Node(data);
    else
        parent->right = new Node(data);
}
int main(){
    Node* root = new Node(18);
    //insertn(root,40,0);
    insertn(root,20,1);
    insertn(root,4,0);
    insertn(root->right,70,1);
    insertn(root->right,13,0);
    //insertn(root->left->right,10,1);
    //insertn(root->right,5,0);
    bool x =checkbaltree(root);
    cout<<"Balance Tree check:"<<x<<endl;
}
