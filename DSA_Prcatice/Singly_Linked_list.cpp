#include <iostream>
#include <string>
using namespace std;
struct Call {
    string number;
    int duration;
    Call* next;
};
class CallLog {
    Call* head = NULL;
public:
    // Insert call at beginning
    void insert(string number, int duration) {
        Call* newNode = new Call;

        newNode->number = number;
        newNode->duration = duration;
        newNode->next = head;

        head = newNode;

        cout << "Call inserted successfully.\n";
    }
    // Search call
    Call* search(string number) {
        Call* temp = head;
        while (temp != NULL) {
            if (temp->number == number)
                return temp;
            temp = temp->next;
        }
        return NULL;
    }
    // Update call duration
    void update(string number, int duration) {
        Call* temp = search(number);
        if (temp != NULL) {
            temp->duration = duration;
            cout << "Call updated successfully.\n";
        }
        else {
            cout << "Call not found.\n";
        }
    }
    // Delete call
    void deleteCall(string number) {
        Call* temp = head;
        Call* prev = NULL;
        while (temp != NULL && temp->number != number) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Call not found.\n";
            return;
        }
        if (prev == NULL)
            head = temp->next;
        else
            prev->next = temp->next;
        delete temp;
        cout << "Call deleted successfully.\n";
    }
    // Sort calls by duration
    void sort() {
        for (Call* i = head; i != NULL; i = i->next) {
            for (Call* j = i->next; j != NULL; j = j->next) {
                if (j->duration < i->duration) {
                    swap(i->number, j->number);
                    swap(i->duration, j->duration);
                }
            }
        }
        cout << "Calls sorted by duration.\n";
    }
    // Display calls
    void display() {
        if (head == NULL) {
            cout << "Call log is empty.\n";
            return;
        }
        Call* temp = head;
        cout << "\n--- Call Log ---\n";
        while (temp != NULL) {
            cout << "Phone Number: " << temp->number << endl;
            cout << "Duration: " << temp->duration << " seconds" << endl;
            temp = temp->next;
        }
    }
    // Destructor
    ~CallLog() {
        while (head != NULL) {
            Call* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
int main() {
    CallLog log;
    int choice;
    string number;
    int duration;
    do {
        cout << "\nCALL LOG MANAGEMENT\n";
        cout << "1. Insert Call\n";
        cout << "2. Display Calls\n";
        cout << "3. Search Call\n";
        cout << "4. Update Call\n";
        cout << "5. Sort Calls\n";
        cout << "6. Delete Call\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter Phone Number: ";
            cin >> number;

            cout << "Enter Duration: ";
            cin >> duration;

            log.insert(number, duration);
            break;
        case 2:
            log.display();
            break;
        case 3:
            cout << "Enter Phone Number to search: ";
            cin >> number;

            if (log.search(number) != NULL)
                cout << "Call found.\n";
            else
                cout << "Call not found.\n";
            break;
        case 4:
            cout << "Enter Phone Number: ";
            cin >> number;

            cout << "Enter New Duration: ";
            cin >> duration;

            log.update(number, duration);
            break;
        case 5:
            log.sort();
            break;
        case 6:
            cout << "Enter Phone Number to delete: ";
            cin >> number;

            log.deleteCall(number);
            break;
        case 7:
            cout << "Thank You\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 7);
    return 0;
}