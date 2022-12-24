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

Node* floydDetectLoop(Node* head){
    if(head ==  NULL){
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;
    while(slow != NULL && fast !=NULL){
        fast = fast -> next -> next;
        if(fast !=NULL){
            fast = fast -> next;
        }
        slow = slow -> next;
        if(slow == fast){
            return slow;
        }
    }
    cout << "No loop detected" << endl;
    return NULL;
}

//get starting node of the loop
Node* getStartingLoop(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node* intersection = floydDetectLoop(head);
    Node* slow = head;
    while(slow != intersection){
        slow = slow->next;
        intersection = intersection ->next;
    }
    return slow;
}

//Remove loop
void removeLoop(Node* head){
    if(head == NULL){
        return;
    }
    Node* start = getStartingLoop(head);
    Node* temp = start;
    while(temp -> next != start){
        temp = temp->next;
    }
    temp -> next = NULL;
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
    tail -> next = head->next;
    cout << tail->next->data << endl;

    if(floydDetectLoop(head) != NULL){
        cout << "Loop is detected " << endl;
    }
    Node* start = getStartingLoop(head);
    cout << "Starting node of the loop is: " << start->data <<endl;
    removeLoop(head);
    cout << tail->next << endl;
    print(head);


    return 0;
}