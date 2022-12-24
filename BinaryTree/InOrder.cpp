#include<iostream>
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

void inorderRecursive(node* root){
    if(root == NULL){
        return ;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    node* root = NULL;
    //creating a tree
    cout << "Enter the data for node: " << endl;
    root = buildtree(root);

    //to add ->  1 3 7 -1 -1 11 -1 -1  5 17 -1 -1 -1 
    cout << "Printing tree: " << endl;
    inorderRecursive(root);

    return 0;
}