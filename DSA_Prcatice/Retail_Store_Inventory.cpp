#include <iostream>
using namespace std;

int main() {
    int size = 7;
    int codes[7] = {0};   // 0 means empty
    int stock[7] = {0};
    double price[7] = {0.0};

    int choice = 0;

    while (choice != 5) {
        cout << "\nINVENTORY MENU\n";
        cout << "1. Add Product\n";
        cout << "2. Search Product\n";
        cout << "3. Restock Product\n";
        cout << "4. Display Inventory\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) { // INSERT
            int code, qty;
            double p;
            cout << "Enter Product Code: ";
            cin >> code;
            cout << "Enter Quantity: ";
            cin >> qty;
            cout << "Enter Price: ";
            cin >> p;

            int slot = code % size;
            int step = 0;
            bool inserted = false;

            while (step < size) {
                if (codes[slot] == 0) {
                    codes[slot] = code;
                    stock[slot] = qty;
                    price[slot] = p;
                    cout << "Success: Product placed at Slot " << slot << "\n";
                    inserted = true;
                    break;
                }
                slot = (slot + 1) % size; // Linear probing
                step++;
            }

            if (!inserted) {
                cout << "Error: Inventory is full!\n";
            }

        } else if (choice == 2) { // SEARCH
            int search_code;
            cout << "Enter Product Code to search: ";
            cin >> search_code;

            int slot = search_code % size;
            int step = 0;
            bool found = false;

            while (step < size && codes[slot] != 0) {
                if (codes[slot] == search_code) {
                    cout << "Found at Slot " << slot << ":\n";
                    cout << "  Stock: " << stock[slot] << " units\n";
                    cout << "  Price: $" << price[slot] << "\n";
                    found = true;
                    break;
                }
                slot = (slot + 1) % size;
                step++;
            }

            if (!found) {
                cout << "Product not found!\n";
            }

        } else if (choice == 3) { // RESTOCK
            int update_code, add_qty;
            cout << "Enter Product Code to restock: ";
            cin >> update_code;
            cout << "Enter Quantity to add: ";
            cin >> add_qty;

            int slot = update_code % size;
            int step = 0;
            bool updated = false;

            while (step < size && codes[slot] != 0) {
                if (codes[slot] == update_code) {
                    stock[slot] += add_qty;
                    cout << "Restocked! New Stock for " << update_code << " is " << stock[slot] << "\n";
                    updated = true;
                    break;
                }
                slot = (slot + 1) % size;
                step++;
            }

            if (!updated) {
                cout << "Product not found!\n";
            }

        } else if (choice == 4) { // DISPLAY
            cout << "\n--- CURRENT TABLE ---\n";
            for (int i = 0; i < size; i++) {
                cout << "Slot " << i << ": ";
                if (codes[i] == 0) {
                    cout << "[ EMPTY ]\n";
                } else {
                    cout << "[ Code: " << codes[i] << " | Stock: " << stock[i] << " | Price: $" << price[i] << " ]\n";
                }
            }
        }
    }

    cout << "Exiting system. Goodbye!\n";
    return 0;
}