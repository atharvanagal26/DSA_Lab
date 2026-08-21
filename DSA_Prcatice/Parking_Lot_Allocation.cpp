#include <iostream>
using namespace std;

int main() {
    const int TOTAL_SLOTS = 7;
    int parking_lot[7];

    // Initialize all parking slots to -1 (indicating EMPTY)
    for (int i = 0; i < TOTAL_SLOTS; i++) {
        parking_lot[i] = -1;
    }

    // Car registration numbers to park
    int cars[5] = {1234, 5678, 4321, 8765, 9999};
    int total_cars = 5;

    cout << "Parking Allocation Log\n";

    // Park each car using Hashing with Linear Probing
    for (int i = 0; i < total_cars; i++) {
        int car_num = cars[i];
        
        // 1. Calculate preferred spot using Hash Function
        int preferred_spot = car_num % TOTAL_SLOTS;
        int current_spot = preferred_spot;
        bool allocated = false;

        // 2. Linear Probing Loop
        for (int step = 0; step < TOTAL_SLOTS; step++) {
            // Check if current slot is empty
            if (parking_lot[current_spot] == -1) {
                parking_lot[current_spot] = car_num;
                allocated = true;

                if (current_spot == preferred_spot) {
                    cout << "Car " << car_num << " -> Parked at preferred Spot " << current_spot << "\n";
                } else {
                    cout << "Car " << car_num << " -> Collision at Spot " << preferred_spot 
                         << "! Reassigned to Spot " << current_spot << "\n";
                }
                break; // Car successfully parked, stop probing
            }

            // Move to next slot linearly (wrap around using modulo)
            current_spot = (current_spot + 1) % TOTAL_SLOTS;
        }

        // If loop finished without allocation, lot is full
        if (!allocated) {
            cout << "Car " << car_num << " -> COULD NOT PARK! Lot is full.\n";
        }
    }

    // 3. Display Final Parking Lot Status
    cout << "\n--- Final Parking Lot Status ---\n";
    for (int i = 0; i < TOTAL_SLOTS; i++) {
        cout << "Slot " << i << ": ";
        if (parking_lot[i] == -1) {
            cout << "[ EMPTY ]\n";
        } else {
            cout << "[ Car " << parking_lot[i] << " ]\n";
        }
    }

    return 0;
}