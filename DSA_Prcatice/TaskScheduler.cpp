#include <iostream>
#include <deque>
#include <string>
using namespace std;
struct Task {
    int id;
    string name;
    int priority;
};
deque<Task> tasks;
void addFront() {
    Task t;
    cout << "Enter Task ID: ";
    cin >> t.id;
    cout << "Enter Task Name: ";
    cin >> ws;
    getline(cin, t.name);
    cout << "Enter Priority (1-High, 2-Medium, 3-Low): ";
    cin >> t.priority;
    tasks.push_front(t);
    cout << "Task added at front successfully!\n";
}
void addRear() {
    Task t;
    cout << "Enter Task ID: ";
    cin >> t.id;
    cout << "Enter Task Name: ";
    cin >> ws;
    getline(cin, t.name);
    cout << "Enter Priority (1-High, 2-Medium, 3-Low): ";
    cin >> t.priority;
    tasks.push_back(t);
    cout << "Task added at rear successfully!\n";
}
void processTask() {
    if (tasks.empty()) {
        cout << "No tasks available!\n";
        return;
    }
    int index = 0;
    for (int i = 1; i < (int)tasks.size(); i++) {
        if (tasks[i].priority < tasks[index].priority) {
            index = i;
        }
    }
    cout << "\nProcessing Task:\n";
    cout << "Task ID: " << tasks[index].id << endl;
    cout << "Task Name: " << tasks[index].name << endl;
    cout << "Priority: " << tasks[index].priority << endl;
    tasks.erase(tasks.begin() + index);
    cout << "Task processed successfully!\n";
}
void displayTasks() {
    if (tasks.empty()) {
        cout << "No tasks available!\n";
        return;
    }
    cout << "\nTASK LIST\n";
    for (int i = 0; i < (int)tasks.size(); i++) {
        cout << "\nTask ID: " << tasks[i].id;
        cout << "\nTask Name: " << tasks[i].name;
        cout << "\nPriority: " << tasks[i].priority << endl;
    }
}
void removeFront() {
    if (tasks.empty()) {
        cout << "Deque is empty!\n";
        return;
    }
    cout << "Removed task: " << tasks.front().name << endl;
    tasks.pop_front();
}
void removeRear() {
    if (tasks.empty()) {
        cout << "Deque is empty!\n";
        return;
    }
    cout << "Removed task: " << tasks.back().name << endl;
    tasks.pop_back();
}
int main() {
    int choice;
    do {
        cout << "\nTASK SCHEDULER\n";
        cout << "1. Add Task at Front\n";
        cout << "2. Add Task at Rear\n";
        cout << "3. Process Highest Priority Task\n";
        cout << "4. Display All Tasks\n";
        cout << "5. Remove Task from Front\n";
        cout << "6. Remove Task from Rear\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addFront();
                break;
            case 2:
                addRear();
                break;
            case 3:
                processTask();
                break;
            case 4:
                displayTasks();
                break;
            case 5:
                removeFront();
                break;
            case 6:
                removeRear();
                break;
            case 0:
                cout << "The End...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);
    return 0;
}
