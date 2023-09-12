#include <iostream>
using namespace std;

class Node {
        public:
        int data;
        Node* next;

        Node() {
                this->data = 0;
                this->next = NULL;
        }
        Node(int data) {
                this->data = data;
                this->next = NULL;
        }
};

//I want to insert a node right at the head of Linked List
void insertAtHead(Node* &head, Node* &tail, int data) {
        //check for Empty LL
        if(head == NULL) {
                Node* newNode = new Node(data);
                head = newNode;
                tail = newNode;
        }
        else {
                //step1:
                Node* newNode = new Node(data);
                //step2:
                newNode -> next = head;
                //step3:
                head = newNode;
        }


}
//I want to insert a node right at the end of LINKED LIST
void insertAtTail(Node* &head,Node* &tail, int data) {
        if(head == NULL) {
                Node* newNode = #include<iostream>
                #include <bits/stdc++.h>
                using namespace std;
                
                class Node{
                    public:
                    int data;
                    Node* next;
                
                    Node(int data){
                        this -> data = data;
                        this -> next = NULL;
                    }
                    ~Node(){
                        int value = this -> data;
                        if(this -> next != NULL){
                            delete next;
                            this->next = NULL;
                        }
                        cout << "memory free for data " << value << endl;
                    }
                };
                
                //insert after head
                void insertAfterHead(Node* &head, int data){
                    Node* temp = new Node(data);
                    head -> next = temp;
                }
                
                // insert after the tail node
                void insertAfterTail(Node* &head, int data){
                    Node* newNode = new Node(data);
                    Node* temp = head;
                    while(temp->next){
                        temp = temp->next;
                    }
                    temp->next = newNode;
                    newNode->next = NULL;
                }
                
                //printing a Linked List
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
                    Node* node1 = new Node(10);
                    Node* head = node1;
                    Node* tail = node1;
                
                    insertAfterHead(head, 20);
                    insertAfterTail(head, 30);
                    print(head);
                
                    return 0;
                }new Node(data);
                head = newNode;
                tail = newNode;
                return;
        }
        //step1: creatae a node
        Node* newNode = new Node(data);
        //step2: connect woth tail ndoe
        tail->next = newNode;
        //step3: update tail;
        tail = newNode;
}
void print(Node* head) {

        Node* temp = head;
        while(temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
        }
}

int findLength(Node* &head ) {
        int len = 0;
        Node* temp = head;
        while(temp != NULL) {
                temp = temp->next;
                len++;
        }
        return len;
}

void insertAtPosition(int data, int position, Node* &head, Node* &tail) {
        if(head == NULL) {
                Node* newNode = new Node(data);
                head = newNode;
                tail = newNode;
                return;
        }
        //step1: find the position: prev & curr;

        if(position == 0) {
                insertAtHead(head, tail , data);
                return;
        }
       
        int len = findLength(head);
        
        if(position >= len) {
                insertAtTail(head, tail, data);
                return;
        }
        //ste1:find prev and curr
        int i = 1;
        Node* prev = head;
        while(i < position) {
                prev= prev -> next;
                i++;
        }
        Node* curr = prev -> next;

        //step2;
        Node* newNode = new Node(data);

        //step3:
        newNode -> next = curr;

        //step4:
        prev -> next = newNode;
}

int main() {

        Node* head = NULL;
        Node* tail = NULL;
        insertAtHead(head, tail,20);
        insertAtHead(head, tail,50);
        insertAtHead(head, tail,60);
        insertAtHead(head,tail, 90);
        insertAtTail(head, tail, 77);

        print(head);
        cout << endl;
        // cout << "head: " << head -> data << endl;
        // cout << "tail: " << tail->data << endl;

        insertAtPosition(101, 5, head, tail);
        cout<< "Printing after insert at position call" << endl;
        print(head);
        cout << endl;
        cout << "head: " << head -> data << endl;
        cout << "tail: " << tail->data << endl;

        return 0;
}