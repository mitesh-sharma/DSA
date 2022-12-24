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

void insertInPosition( Node* &head, int position, int data){

    Node* temp = head;
    int i=1;
    while(i < position-1){
        temp = temp->next;
        i++;
    }
    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
    
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

Node* reverse(Node* &head){
    if(head == NULL || head ->next == NULL){
        return head;
    }

    Node* prev = NULL;
    Node* current = head;
    Node* forward;
    while(current != NULL){
        forward = current->next;
        current->next = prev;
        prev = current;
        current = forward;
        head = prev;
    }
    return prev;
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

    reverse(head);
    print(head);
    reverse(head);
    print(head);

    return 0;
}