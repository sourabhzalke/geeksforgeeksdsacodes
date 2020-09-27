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
unordered_map<Node*,int> uh;
void insertn(Node* parent,int data,int side){
    if(side==0)
        parent->left = new Node(data);
    else
        parent->right = new Node(data);
}
int res=0;
int diaHeight(Node* root){
    if(root==NULL)
        return 0;
    int lh = diaHeight(root->left);
    int rh = diaHeight(root->right);
    res = max(res,lh+rh+1);
    return 1+max(lh,rh);

}
int height(Node* root){
        if(root==NULL)
            return 0;
        int h = max(height(root->left),height(root->right))+1;
        uh[root]=h;
        return h;
}
//This has time complexity T(n)=T(n-1)+Theta(n)= O(n^2)
/*
int diameter(Node* root){
    if(root==NULL)
        return 0;
    int di =  height(root->left)+height(root->right)+1;
    int leftd = diameter(root->left);
    int rightd = diameter(root->right);
    return max(di,max(leftd,rightd));
}
*/
//This solution will give O(n) complexity
int diameter(Node* root){
    if(root==NULL)
        return 0;
    int di =  uh[root->left]+uh[root->right]+1;
    int leftd = diameter(root->left);
    int rightd = diameter(root->right);
    return max(di,max(leftd,rightd));
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

int main(){ 
    Node *root = new Node(10);
    insertn(root,20,0);
    insertn(root,60,1);
    insertn(root->left,30,0);
    insertn(root->left,80,1);
    insertn(root->left->right,90,1);
    insertn(root->left->right->right,18,1);
    insertn(root->left->left,40,0);
    insertn(root->left->left,50,1);
    insertn(root->left->left->left,60,0);
    height(root);
    bfs(root);
    cout<<"\n";
    cout<<"Iterating over Unorder Map:\n";
    for(auto x : uh)
        cout<<x.first->data<<" "<<x.second<<" ";
    cout<<"\n";
    int di = diameter(root);
    cout<<"The diameter of the Binary Tree is: "<<di<<"\n";
    diaHeight(root);
    cout<<"The diameter of the Binary Tree without using extra O(n) space of Unorder Map is: "<<res<<"\n";
}
