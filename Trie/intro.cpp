#include <iostream>
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

void insert(TrieNode* root, string s){

    for(int i=0; i<s.length(); i++){
        char ch = s[i];
        int index = ch - 'a';
        if(root->children[index] != NULL){
            root = root->children[index];
        }
        else{
            TrieNode* newNode = new TrieNode(ch);
            root->children[index] = newNode;
            root = root->children[index];
        }
        if(i == s.length()-1){
            root->isEnd = true;
        }
    }
}

bool isPresent(TrieNode* root, string word, int i){
  if(i == word.length()){
    if(root->isEnd == true){
      return true;
    }
    else{
      return false;
    }
  }
  
  char c = word[i];
  int index = c - 'a';
  TrieNode* child;
  if(root->children[index] != NULL){
    child = root->children[index];
  }
  else{
    return false;
  }
  return isPresent(child, word, i+1);
}

bool doesContain(TrieNode* root, string word, int i){
  if(i == word.length()){
      return true;
  }
  char c = word[i];
  int index = c - 'a';
  TrieNode* child;
  if(root->children[index] != NULL){
    child = root->children[index];
  }
  else{
    return false;
  }
  return doesContain(child, word, i+1);
}

int main() {
  //only lower case words allowed
  TrieNode* root = new TrieNode('-');

  insert(root, "code");
  insert(root, "coding");
  insert(root, "coder");

  //is the word present
  if(isPresent(root, "cud", 0)){
    cout << "Present" << endl;
  }
  else{
    cout << "Absent" << endl;
  }

  //is the word contained by any word
  if(doesContain(root, "cod", 0)){
    cout << "Contains" << endl;
  }
  else{
    cout << "Does not contain" << endl;
  }

}