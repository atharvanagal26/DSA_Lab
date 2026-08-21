#include <iostream>
using namespace std;

const int SIZE = 10;

// Hash table
int hashTable[SIZE];

// Initialize hash table
void initialize()
{
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

// Hash function
int hashFunction(int key)
{
    return key % SIZE;
}

// Insert using linear probing
void insert(int key)
{
    int index = hashFunction(key);
    int startIndex = index;

    // Find next empty location
    while (hashTable[index] != -1)
    {
        index = (index + 1) % SIZE;

        // Table is full
        if (index == startIndex)
        {
            cout << "Hash table is full.\n";
            return;
        }
    }

    hashTable[index] = key;

    cout << key << " inserted at index " << index << endl;
}

// Search using linear probing
void search(int key)
{
    int index = hashFunction(key);
    int startIndex = index;

    while (hashTable[index] != -1)
    {
        if (hashTable[index] == key)
        {
            cout << key << " found at index "
                 << index << endl;
            return;
        }

        index = (index + 1) % SIZE;

        if (index == startIndex)
            break;
    }

    cout << key << " not found.\n";
}

// Display hash table
void display()
{
    cout << "\nIndex\tValue\n";
    cout << "----------------\n";

    for (int i = 0; i < SIZE; i++)
    {
        cout << i << "\t";

        if (hashTable[i] == -1)
            cout << "Empty";
        else
            cout << hashTable[i];

        cout << endl;
    }
}

int main()
{
    initialize();

    int choice, key;

    do
    {
        cout << "\n===== HASH TABLE =====\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter key: ";
                cin >> key;
                insert(key);
                break;

            case 2:
                cout << "Enter key to search: ";
                cin >> key;
                search(key);
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}