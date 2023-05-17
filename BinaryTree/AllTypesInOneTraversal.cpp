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

void allTraversalsInOne(node* root, vector <int> &preOrder, vector <int> &inOrder, vector <int> &postOrder){
    stack <pair<node*, int>> st;
    st.push({root, 1});

    while(!st.empty()){
        auto it = st.top();
        st.pop();
        if(it.second == 1){
            preOrder.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->left != NULL){
                st.push({it.first->left, 1});
            }
        }
        else if(it.second == 2){
            inOrder.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right != NULL){
                st.push({it.first->right, 1});
            }
        }
        else{
            postOrder.push_back(it.first->data);
        }

    }
    
}

int main()
{
    //to add ->  1 3 7 -1 -1 11 -1 -1  5 17 -1 -1 -1 
    node* root = NULL;
    cout << "Enter the data for node: " << endl;
    root = buildtree(root);
    cout << "Printing tree using recursion: " << endl;

    cout << "All traversals: " << endl;
    vector <int> pre;
    vector <int> in;
    vector <int> post;
    allTraversalsInOne(root, pre, in, post);

    cout << "PreOrder: ";
    for(int i=0; i< pre.size(); i++){
        cout << pre[i] << " ";
    }
    cout << endl;
    cout << "InOrder: ";
    for(int i=0; i < in.size(); i++){
        cout << in[i] << " ";
    }
    cout << endl;
    cout << "PostOrder: ";
    for(int i=0; i< post.size(); i++){
        cout << post[i] << " ";
    }
    cout << endl;


    return 0;
}