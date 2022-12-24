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

//this function is to assign the last value as tail
Node* assignTail(Node* head){
    Node* temp = head;
    Node* tail = NULL;
    while(temp->next != NULL){
        temp = temp->next;
    }
    tail = temp;
    return tail;
}

//function to detect if a loop is present or not
bool detectLoop(Node* head){
    //for empty list
    if(head == NULL){
        return false;
    }
    map <Node*, bool> visited;
    Node* temp = head;
    while(temp != NULL){
        if(visited[temp] == true){
            cout << "A loop is found at: " << temp->data << endl;
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    cout << "No loop is found " << endl;
    return false;
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
        cout << "Enter the element: ";
        int x;
        cin >> x;
        insertInPosition(head, i, x);
    }
    print(head);

    //assigning the next of tail to head->next->next i.e. 3
    //hence creating a loop
    tail = assignTail(head);
    cout << tail->data << endl;
    cout << tail->next << endl;
    tail->next = head->next;
    //cout << tail->next->data << endl;

    // Till now I created a linked list with a loop in it
    //Below this would be the code to detect a loop in a linked list

    detectLoop(head);
    
    return 0;
}