#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class TrieNode{
  public:
    char data;
    TrieNode *children[26];
    bool isEnd;

    TrieNode(char d){
      data = d;
      for(int i=0; i<26; i++){
        children[i] = NULL;
      }
      isEnd = false;
    }

};
void insert(TrieNode* root, string word, int i){

  if(i == word.length()){
    root->isEnd = true;
    return;
  }
  
  char c = word[i];
  int index = c - 'a';
  TrieNode* child;
  if(root->children[index] != NULL){
    child = root->children[index];
  }
  else{
    TrieNode* newNode = new TrieNode(c);
    root->children[index] = newNode;
    child = root->children[index];
  }
  insert(child, word, i+1);
}


void traverse(TrieNode* root, vector <string>& temp, string& prefix){
    if(root->isEnd){
        temp.push_back(prefix);
    }
    for(int i=0; i<26; i++){
        auto nextNode = root->children[i];
        if(nextNode != NULL){
            prefix.push_back(nextNode->data);
            traverse(nextNode, temp, prefix);
            prefix.pop_back();
        }
    }
}

vector <vector<string>> autoComplete(TrieNode* root, string word){
    vector <vector <string>> ans;
    string prefix;
    for(int i=0; i<word.length(); i++){
        char ch = word[i];
        int index = ch - 'a';
        auto nextch = root->children[index];
        if(nextch != NULL){
            prefix += ch;
            vector <string> temp;
            traverse(nextch, temp, prefix);
            ans.push_back(temp);
        }
        root = nextch;
    }
    return ans;
}

int main() {
    //only lower case words allowed
    TrieNode* root = new TrieNode('-');
    insert(root, "code", 0);
    insert(root, "coder", 0);
    insert(root, "coding", 0);
    insert(root, "cap", 0);
    insert(root, "cat", 0);
    insert(root, "call", 0);
    insert(root, "ceo", 0);
    insert(root, "cement", 0);
    insert(root, "cinema", 0);
    insert(root, "cut", 0);
    insert(root, "curtain", 0);
    insert(root, "laptop", 0);
    insert(root, "live", 0);
    insert(root, "lamp", 0);

    string word = "co";
    vector <vector <string>> ans = autoComplete(root, word);

    string x = "";

    cout << endl;
    for(int i=0; i<ans.size(); i++){
      x += word[i];
      cout << x << " --> ";
      for(int j=0; j<ans[i].size(); j++){
          cout << ans[i][j] << " ";
      }
      cout << endl;
    }
    
    return 0;
}