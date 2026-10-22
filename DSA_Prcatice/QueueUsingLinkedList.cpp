#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
class Queue {
    Node* front;
    Node* rear;
public:
    Queue() {
        front = rear = NULL;
    }
    void enqueue(int x) {
        Node* newNode = new Node;
        newNode->data = x;
        newNode->next = NULL;
        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << x << " inserted into queue\n";
    }
    void dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow!\n";
            return;
        }
        Node* temp = front;
        cout << "Deleted element: " << front->data << endl;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        delete temp;
    }
    void peek() {
        if (front == NULL) {
            cout << "Queue is empty!\n";
        } else {
            cout << "Front element: " << front->data << endl;
        }
    }
    void display() {
        if (front == NULL) {
            cout << "Queue is empty!\n";
            return;
        }
        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    ~Queue() {
        while (front != NULL) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};
int main() {
    Queue q;
    int choice, x;
    do {
        cout << "\nQUEUE USING LINKED LIST\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter element: ";
                cin >> x;
                q.enqueue(x);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                q.display();
                break;
            case 5:
                cout << "The End...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);
    return 0;
}
