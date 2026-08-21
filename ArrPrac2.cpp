#include<iostream>
using namespace std;

int main () {
    int n, i;
    cout << "Enter no of elements in array : ";
    cin >> n;

    int arr[100]; 

    cout << "Enter the elements of the array: \n";
    for (i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    int choice;

    do {
        cout << "1. Display Array\n";
        cout << "2. Insertion (Add Element)\n";
        cout << "3. Updation (Modify Element)\n";
        cout << "4. Deletion (Remove Element)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {

            // 1. DISPLAY
            case 1: {
                if (n == 0) {
                    cout << "[Info] Array is currently empty.\n";
                } else {
                    cout << "The elements of the array are: ";
                    for (i = 0; i < n; i++) {
                        cout << arr[i] << " ";
                    }
                    cout << endl;
                }
                break;
            }

            //2. INSERTION
            case 2: {
                int insVal, insPos;
                if (n >= 100) {
                    cout << "[Error] Array Capacity Reached (Max 100)!\n";
                    break;
                }

                cout << "Enter element to insert: ";
                cin >> insVal;
                cout << "Enter Position (1 to " << n + 1 << "): ";
                cin >> insPos;

                if (insPos < 1 || insPos > n + 1) {
                    cout << "[Error] Invalid position for insertion!\n";
                } else {
                    // Shift elements RIGHT
                    for (i = n; i >= insPos; i--) {
                        arr[i] = arr[i - 1];
                    }
                    arr[insPos - 1] = insVal; // Insert new element
                    n++;                      // Increase element count
                    cout << "[Success] Element inserted successfully.\n";
                }
                break;
            }

            // 3. UPDATION
            case 3: {
                int updPos, newVal;
                if (n == 0) {
                    cout << "[Error] Array is empty! Nothing to update.\n";
                    break;
                }

                cout << "Enter Position to update (1 to " << n << "): ";
                cin >> updPos;

                if (updPos < 1 || updPos > n) {
                    cout << "[Error] Invalid position for updation!\n";
                } else {
                    cout << "Enter new value: ";
                    cin >> newVal;

                    int oldVal = arr[updPos - 1];
                    arr[updPos - 1] = newVal; // Overwrite element

                    cout << "[Success] Updated position " << updPos << " from " << oldVal << " to " << newVal << ".\n";
                }
                break;
            }

            // 4. DELETION
            case 4: {
                int delPos;
                if (n == 0) {
                    cout << "[Error] Array is empty! Nothing to delete.\n";
                    break;
                }

                cout << "Enter Position to delete (1 to " << n << "): ";
                cin >> delPos;

                if (delPos < 1 || delPos > n) {
                    cout << "[Error] Invalid position for deletion!\n";
                } else {
                    int deletedVal = arr[delPos - 1];

                    // Shift elements LEFT
                    for (i = delPos - 1; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    n--; // Decrease element count

                    cout << "[Success] Deleted element: " << deletedVal << " from position " << delPos << ".\n";
                }
                break;
            }

            //5. EXIT
            case 5:
                cout << "\nExiting application. Goodbye!\n";
                break;

            default:
                cout << "\n[Error] Invalid choice! Please enter a number from 1 to 5.\n";
        }

    } while (choice != 5);

    return 0;
}