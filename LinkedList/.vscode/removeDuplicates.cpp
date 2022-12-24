#include<iostream>
#include <map>
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

//print the linked list
void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

//insert at a position
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

//find and remove duplicates in a sorted linked list
Node* duplicateInSorted(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node* curr = head;
    while(curr!= NULL){
        if((curr->next!= NULL)&&(curr -> data == curr->next->data)){
            Node* next_next = curr->next->next;
            Node* nodeToDelete = curr->next;
            delete (nodeToDelete);
            curr->next = next_next;
        }
        else{
            curr = curr->next;
        }
    }
    return head;
}

//find and remove duplicates in an unsorted linked list
//Time Copmlexity O(n^2)
Node* duplicateInUnsorted(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node* curr = head;
    while(curr->next != NULL){
        Node* temp = curr;
        while(temp->next != NULL){
            if(curr->data == temp->next->data){
                Node* next_next = temp->next->next;
                Node* nodeToDelete = temp->next;
                delete (nodeToDelete);
                temp->next = next_next;
            }
            else{
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
    return head;
}

int main()
{
    // Creation of a linked list from scratch.
    Node* head = new Node(1);
    Node* tail = new Node(2);
    int n;
    cout << "Enter the length: ";
    cin >> n;
    for(int i=2; i<=n; i++){
        cout << "Enter element "<< i << ": ";
        int x;
        cin >> x;
        insertInPosition(head, i, x);
    }
    print(head);

    //duplicateInSorted(head);
    duplicateInUnsorted(head);

    print(head);
    return 0;
}