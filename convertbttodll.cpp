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
Node* previous = NULL;
Node* btodll(Node* root){
    if(root==NULL)
        return root;
    Node* head = btodll(root->left);
    if(previous==NULL)
        head = root;
    else{
        root->left = previous;
        previous->right = root;
    }
    previous = root;
    btodll(root->right);
    return head;
}

void printList(Node* head)
{
  for ( ; head; head = head->right )
  {
    cout << head->data<<" ";
  }
}

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

int main(){
    Node* prev = NULL;
    Node* root = new Node(10);
    insertn(root,5,0);
    insertn(root,20,1);
    insertn(root->right,30,0);
    insertn(root->right,35,1);
    bfs(root);
    cout<<"\n";
    Node* head = btodll(root);
    printList(head); 

}
