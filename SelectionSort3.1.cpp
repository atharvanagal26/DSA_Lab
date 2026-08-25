#include <iostream>
using namespace std;

int main() {
    int n;
    float marks[100];

    cout << "Enter number of students: ";
    cin >> n;

    cout << "Enter student marks:\n";
    for (int i = 0; i < n; i++) {
        cout << "Mark " << i + 1 << ": ";
        cin >> marks[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; 

        for (int j = i + 1; j < n; j++) {
            if (marks[j] < marks[minIndex]) {
                minIndex = j; 
            }
        }

        float temp = marks[i];
        marks[i] = marks[minIndex];
        marks[minIndex] = temp;
    }

    cout << "\nSorted Marks in Ascending Order:\n";
    for (int i = 0; i < n; i++) {
        cout << marks[i] << " ";
    }
    cout << endl;

    return 0;
}