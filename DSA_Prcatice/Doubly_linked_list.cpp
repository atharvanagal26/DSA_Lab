#include <iostream>
#include <string>
using namespace std;
struct Node {
    string name;
    int age;
    string trainName;
    int seatNo;

    Node* prev;
    Node* next;
};
Node* head = NULL;
// Add Reservation
void addReservation() {
    Node* newNode = new Node;

    cout << "Enter Passenger Name: ";
    cin >> newNode->name;

    cout << "Enter Age: ";
    cin >> newNode->age;

    cout << "Enter Train Name: ";
    cin >> newNode->trainName;

    cout << "Enter Seat Number: ";
    cin >> newNode->seatNo;

    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } 
    else {
        Node* temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }
    cout << "Reservation added successfully.\n";
}
// Display Reservations
void displayReservations() {
    if (head == NULL) {
        cout << "No reservations found.\n";
        return;
    }
    Node* temp = head;
    cout << "\nTrain Reservations\n";
    while (temp != NULL) {
        cout << "Passenger Name: " << temp->name << endl;
        cout << "Age: " << temp->age << endl;
        cout << "Train Name: " << temp->trainName << endl;
        cout << "Seat Number: " << temp->seatNo << endl;
        temp = temp->next;
    }
}
// Display in Reverse
void displayReverse() {
    if (head == NULL) {
        cout << "No reservations found.\n";
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    cout << "\nReservations in Reverse\n";
    while (temp != NULL) {
        cout << "Passenger Name: " << temp->name << endl;
        cout << "Age: " << temp->age << endl;
        cout << "Train Name: " << temp->trainName << endl;
        cout << "Seat Number: " << temp->seatNo << endl;
        temp = temp->prev;
    }
}
// Search Reservation
void searchReservation() {
    int seatNo;

    cout << "Enter Seat Number to search: ";
    cin >> seatNo;
    Node* temp = head;
    while (temp != NULL) {
        if (temp->seatNo == seatNo) {
            cout << "\nReservation Found\n";
            cout << "Passenger Name: " << temp->name << endl;
            cout << "Age: " << temp->age << endl;
            cout << "Train Name: " << temp->trainName << endl;
            cout << "Seat Number: " << temp->seatNo << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Reservation not found.\n";
}
// Cancel Reservation
void cancelReservation() {
    int seatNo;
    cout << "Enter Seat Number to cancel: ";
    cin >> seatNo;
    Node* temp = head;
    while (temp != NULL && temp->seatNo != seatNo)
        temp = temp->next;
    if (temp == NULL) {
        cout << "Reservation not found.\n";
        return;
    }
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    delete temp;
    cout << "Reservation cancelled successfully.\n";
}
int main() {
    int choice;
    do {
        cout << "\nTrain Reservation System\n";
        cout << "1. Add Reservation\n";
        cout << "2. Display Reservations\n";
        cout << "3. Display Reverse\n";
        cout << "4. Search Reservation\n";
        cout << "5. Cancel Reservation\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addReservation();
                break;
            case 2:
                displayReservations();
                break;
            case 3:
                displayReverse();
                break;
            case 4:
                searchReservation();
                break;
            case 5:
                cancelReservation();
                break;
            case 6:
                cout << "Thank You\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 6);
    return 0;
}