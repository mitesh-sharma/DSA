#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertInPosition(Node* &head, int position, int data){

    Node* temp = head;
    int i=1;
    while(i < position-1){
        temp = temp->next;
        i++;
    }
    //creating a node for data
    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
    
}

Node* kreverse(Node* &head, int k){

    if(head == NULL){
        return head;
    }
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    int count = 0;
    while(curr != NULL && count < k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if(next != NULL){
        head->next = kreverse(next, k);
    }
    return prev;
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main()
{
    Node* head = new Node(1);
    int n;
    cout << "Enter the length: ";
    cin >> n;
    for(int i=2; i<=n; i++){
        cout << "Enter the element: ";
        int x;
        cin >> x;
        insertInPosition(head, i, x);
    }
    print(head);

    head = kreverse(head, 3);
    print(head);

    return 0;
}