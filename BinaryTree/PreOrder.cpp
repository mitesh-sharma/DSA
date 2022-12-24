#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;   
    node* right;  

    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    } 
};

node* buildtree(node* root){
    int data;
    cin >> data;
    root = new node(data);
    if(data == -1){
        return NULL;
    }
    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildtree(root->left);

    cout << "Enter data for inserting in right of" << data << endl;
    root->right = buildtree(root->right);

    return root;
}

void preorderRecursive(node* root){
    if(root == NULL){
        return ;
    }

    cout << root->data<< " ";
    preorderRecursive(root->left);
    preorderRecursive(root->right);
}

void preOrderIterative(node* root){
    vector <int> preorder;
    //if(root == NULL) do nothing coz void function
    stack <node*> st;
    while(!st.empty()){
        root = st.top();
        st.pop();
        preorder.push_back(root->data);
        if(root->right != NULL){
            st.push(root->right);
        }
        if(root->left !=NULL){
            st.push(root->left);
        }
    }

    for(int i=0; i< preorder.size(); i++){
        cout << preorder[i] << " ";
    }
    cout << endl;
}


int main()
{
    node* root = NULL;
    //creating a tree
    cout << "Enter the data for node: " << endl;
    root = buildtree(root);
    cout << "Printing tree using recursion: " << endl;

    preorderRecursive(root);
    cout << endl;
    cout << "Printing tree using iteration: " << endl;

    preOrderIterative(root);
    //to add ->  1 3 7 -1 -1 11 -1 -1  5 17 -1 -1 -1 

    return 0;
}