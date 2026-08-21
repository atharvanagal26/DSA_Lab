#include <iostream>
using namespace std;

int main() {
    const int TABLE_SIZE = 7;
    long long library_slots[7]; // Long long used because ISBN numbers are large

    // Initialize all slots to 0 (0 means EMPTY)
    for (int i = 0; i < TABLE_SIZE; i++) {
        library_slots[i] = 0;
    }

    // List of incoming book ISBNs to store
    long long isbns[5] = {9780131101362LL, 9780201633610LL, 9780131103000LL, 9780596009205LL, 9780321563842LL};
    int total_books = 5;

    cout << "--- Library Book Insertion Log ---\n";

    // Insert each book ISBN into the Hash Table
    for (int i = 0; i < total_books; i++) {
        long long current_isbn = isbns[i];

        // 1. Calculate base hash index
        int preferred_slot = current_isbn % TABLE_SIZE;
        int current_slot = preferred_slot;
        bool stored = false;

        // 2. Linear Probing Loop
        for (int step = 0; step < TABLE_SIZE; step++) {
            // Check if slot is empty
            if (library_slots[current_slot] == 0) {
                library_slots[current_slot] = current_isbn;
                stored = true;

                if (current_slot == preferred_slot) {
                    cout << "ISBN " << current_isbn << " -> Stored at initial Slot " << current_slot << "\n";
                } else {
                    cout << "ISBN " << current_isbn << " -> Collision at Slot " << preferred_slot 
                         << "! Probed to Slot " << current_slot << "\n";
                }
                break; // Book successfully stored
            }

            // Move to next adjacent slot (wraps around to 0 at the end)
            current_slot = (current_slot + 1) % TABLE_SIZE;
        }

        // If whole table checked and no empty slot found
        if (!stored) {
            cout << "ISBN " << current_isbn << " -> ERROR: Library Shelf is Full!\n";
        }
    }

    // 3. Display Final Shelf Layout
    cout << "\n--- Final Library Shelf Layout ---\n";
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << "Slot " << i << ": ";
        if (library_slots[i] == 0) {
            cout << "[ EMPTY ]\n";
        } else {
            cout << "[ ISBN: " << library_slots[i] << " ]\n";
        }
    }

    return 0;
}