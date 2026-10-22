#include <iostream>
#include <stack>
using namespace std;

class Queue {
    stack<int> s1, s2;
public:
    void enqueue(int x) {
        s1.push(x);
        cout << x << " inserted into queue\n";
    }
    void dequeue() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue Underflow!\n";
            return;
        }
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        cout << "Deleted element: " << s2.top() << endl;
        s2.pop();
    }
    void peek() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty!\n";
            return;
        }
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        cout << "Front element: " << s2.top() << endl;
    }
    void display() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Queue elements (front to rear): ";
        stack<int> temp = s2;
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        temp = s1;
        stack<int> rev;
        while (!temp.empty()) {
            rev.push(temp.top());
            temp.pop();
        }
        while (!rev.empty()) {
            cout << rev.top() << " ";
            rev.pop();
        }
        cout << endl;
    }
};
int main() {
    Queue q;
    int choice, x;
    do {
        cout << "\nQUEUE USING TWO STACKS\n";
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
