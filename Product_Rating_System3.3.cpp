#include <iostream>
#include <string>

using namespace std;

struct Product {
    string name;
    double rating;
};

int partition(Product arr[], int low, int high) {
    double pivot = arr[high].rating; // Pivot element
    int i = low - 1; // Index of greater element

    for (int j = low; j < high; j++) {
        // Condition for Descending Order: arr[j].rating > pivot
        if (arr[j].rating > pivot) {
            i++;
            // Swap arr[i] and arr[j]
            Product temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Place pivot at its correct position
    Product temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(Product arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        // Sort left and right parts
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    Product products[5] = {
        {"Wireless Mouse", 4.2},
        {"Gaming Laptop", 4.8},
        {"USB Cable", 3.5},
        {"Bluetooth Speaker", 4.5},
        {"Mechanical Keyboard", 4.7}
    };
    int n = 5;

    cout << "--- BEFORE SORTING ---\n";
    for (int i = 0; i < n; i++) {
        cout << products[i].name << " - Rating: " << products[i].rating << "\n";
    }

    // Perform Quick Sort
    quickSort(products, 0, n - 1);

    cout << "\n--- HIGHLY RATED PRODUCTS FIRST (Quick Sort - Descending) ---\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << products[i].name << " - Rating: " << products[i].rating << "\n";
    }

    return 0;
}