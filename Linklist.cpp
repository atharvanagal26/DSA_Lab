#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};
Node* insertAtBeginning(Node* head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    return newNode; 
}
Node* insertAtEnd(Node* head, int value) {
    Node* newNode = new Node(value);
    
    if (head == NULL) { // Updated from nullptr
        return newNode;
    }

    Node* temp = head;
    while (temp->next != NULL) { // Updated from nullptr
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}
Node* insertAfter(Node* head, int afterValue, int value) {
    Node* temp = head;

    while (temp != NULL && temp->data != afterValue) { 
        temp = temp->next;
    }

    if (temp == NULL) { 
        cout << "Node with value " << afterValue << " not found." << endl;
        return head;
    }
    Node* newNode = new Node(value);
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}
Node* deleteNode(Node* head, int value) {
    if (head == NULL) { 
        return NULL; 
    }
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != value) { 
        temp = temp->next;
    }

    if (temp->next == NULL) { 
        cout << "Value " << value << " not found in list." << endl;
        return head;
    }

    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;

    return head;
}
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {  
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}