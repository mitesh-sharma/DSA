#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree(){
    int data;
    cin >> data;

    if(data == -1){
        return NULL;
    }
    Node* root = new Node(data);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

bool solve(Node* root, int& k, int p){
    if(root == NULL){
        return false;
    }
    if(root->data == p){
        return true;
    }

    bool leftAns = solve(root->left, k, p);
    bool rightAns = solve(root->right, k, p);

    if(leftAns || rightAns){
        k--;
    }
    if(k==0){
        cout << "answer is: " << root->data << endl;
        k=-1;
    }
    return leftAns || rightAns;
}

int main() {
  Node* root = NULL;
  root = buildTree();
  int k = 2;
  int p = 60;
  solve(root, k, p);
  return 0;
}