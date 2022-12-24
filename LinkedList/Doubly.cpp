#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this -> data = data;
        this-> prev = NULL;
        this-> next = NULL;
    }
    ~Node(){
        int val = this -> data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout << "Memory for data: " << val << " removed " << endl;
    }
};

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int getlength(Node* &head){
    Node* temp = head;
    int length = 0;
    while(temp !=NULL){
        length++;
        temp = temp->next;
    }
    return length;
}

void insertAtHead(Node* &tail, Node* &head, int data){
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(data);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
}

void insertAtTail(Node* &tail, Node* &head, int data){
    if(tail == NULL){
        Node* temp = new Node(data);
        tail = temp;
        head = temp;
    }
    Node* temp = new Node(data);
    tail->next = temp;
    temp -> prev = tail;
    tail = temp;
}

void insertAtPosition(Node* &tail, Node* &head, int position, int data){

    if (position == 1){
        insertAtHead(tail, head, data);
        return;
    }
    Node* temp = head;
    int i=1;
    while(i < position-1){
        temp = temp->next;
        i++;
    }
    if(temp-> next == NULL){
        insertAtTail(tail, head, data);
        return;
    }
    //creating a node for data
    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    nodeToInsert->prev = temp;
    temp-> next = nodeToInsert;
}

void deleteNode(Node* &head, int position){
    if(position == 1){
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp;
    }
    else{
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        while(cnt < position){
            prev = curr;
            curr = curr -> next;
            cnt++;        
        }
        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}


int main()
{
    Node* node1 = new Node(5);
    Node* head = NULL;
    Node* tail = NULL;

    print(head);
    cout << "The length is: " <<getlength(head) << endl;
    insertAtHead(tail, head, 4);
    insertAtHead(tail, head, 3);
    insertAtHead(tail, head, 2);
    insertAtHead(tail, head, 1);
    print(head);

    insertAtPosition(tail, head, 4, 100);
    insertAtPosition(tail, head, 1, 100);
    insertAtPosition(tail, head, 7, 100);

    insertAtTail(tail,head, 6);
    print(head);
    
    deleteNode(head, 1);
    print(head);
    deleteNode(head, 4);
    print(head);
    deleteNode(head, 5);
    print(head);
    
    return 0;
}