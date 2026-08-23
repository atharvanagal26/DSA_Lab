#include <iostream>
#include <string>
using namespace std;

struct Friend {
    string name;
    string phone;
};

int main() {
    Friend book[100];
    int count = 4;

    book[0] = {"Om", "9876543210"};
    book[1] = {"Ram", "8765432109"};
    book[2] = {"Sham", "7654321098"};
    book[3] = {"David", "6543210987"};

    string target;
    cout << "Enter name to search: ";
    cin >> target;

    // --- SENTINEL SEARCH ---
    book[count].name = target;

    int i = 0;
    while (book[i].name != target) {
        i++;
    }

    if (i < count) {
        cout << "Found: " << book[i].name << " -> " << book[i].phone << "\n";
    } else {
        cout << "Not found! Adding " << target << " to phonebook...\n";

        string mobile;
        cout << "Enter mobile number: ";
        cin >> mobile;

        book[count].name = target;
        book[count].phone = mobile;
        count++;

        int j = count - 1;
        while (j > 0 && book[j].name < book[j - 1].name) {
            Friend temp = book[j];
            book[j] = book[j - 1];
            book[j - 1] = temp;
            j--;
        }

        cout << "Successfully inserted in sorted order!\n";
    }

    cout << "\n--- Updated Phonebook ---\n";
    for (int k = 0; k < count; k++) {
        cout << book[k].name << " : " << book[k].phone << "\n";
    }

    return 0;
}