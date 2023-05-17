#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Node
{
    public:
	    int data;
	    Node *next;
	    Node(int data)
        {
		    this->data = data;
		    this->next = NULL;
	    }
};

void insertAfterHead(Node* &head, int data){
    Node* temp = new Node(data);
    temp->next = head->next;
    head -> next = temp;
}

Node *getListAfterDeleteOperation(Node *head, int n, int m)
{
	int NumberOfNodes = n;
	int gap = m;

	Node* temp = head;

	while(temp->next != NULL){
		while(gap != 1){
			temp = temp->next;
			gap--;
		}
		while(NumberOfNodes){
			Node* go = temp->next;
			temp->next = temp->next->next;
			go->next = NULL;
			NumberOfNodes--;
		}
		gap = m;
		NumberOfNodes = n;
		temp = temp->next;
		
	}
	return head;
}

int main(){
    int n = 1;
    int m = 2;
    Node* head = new Node(3);
    insertAfterHead(head, -1);
    insertAfterHead(head, 5);
    insertAfterHead(head, 10);
    insertAfterHead(head, -8);
    insertAfterHead(head, -9);
    insertAfterHead(head, 7);
    insertAfterHead(head, -4);
    insertAfterHead(head, 0);
    insertAfterHead(head, 2);

    getListAfterDeleteOperation(head, n, m);

    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }



    return 0;
}