#include<iostream>
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

//to insert a node before the head node
void insertAtHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}
void insertAtTail(Node* &tail, int data){
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

//insert after head
void insertAfterHead(Node* &head, int data){
    Node* temp = new Node(data);
    head -> next = temp;
}

//insert after the tail node
// void insertAfterTail(Node* &tail, int data){
//     Node* temp = new Node(data);
//     tail -> next = temp;
//     temp->next = NULL;
// }

//insert at a position
void insertInPosition(Node* &tail, Node* &head, int position, int data){
    if (position == 1){
        insertAtHead(head, data);
        return;
    }
    Node* temp = head;
    int i=1;
    while(i < position-1){
        temp = temp->next;
        i++;
    }
    if(temp-> next == NULL){
        insertAtTail(tail, data);
        return;
    }
    //creating a node for data
    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
    
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
//delete the element at that position
//have to write code for deletion of last element
void deleteNode(Node* &head, int position){
    int i =1;

    if(position ==1){
        Node* temp = head;
        head = head->next; 
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
        prev->next = curr->next;
        curr -> next = NULL;
        delete curr;
    }
}

int main()
{

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    print(head);

    insertAtHead(head, 0);

    insertAtTail(tail, 3);
    print(head);

    insertInPosition(tail, head, 3, 4);
    print(head);

    insertAtTail(tail, 5);
    print(head);

    insertAtTail(tail, 91);
    print(head);
    cout << tail->next << endl;
    
    deleteNode(head, 3);
    deleteNode(head, 1);
    print(head);
    
    //deleteNode(head, 5);
    //print(head);
    return 0;
}