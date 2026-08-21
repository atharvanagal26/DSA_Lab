#include <iostream>
using namespace std;

int main() {
    int n;
    float price[100];

    cout << "Enter number of flight tickets: ";
    cin >> n;

    cout << "Enter ticket prices:\n";
    for (int i = 0; i < n; i++) {
        cout << "Price " << i + 1 << ": Rs.";
        cin >> price[i];
    }

    for (int i = 1; i < n; i++) {
        float key = price[i];
        int j = i - 1;

        while (j >= 0 && price[j] > key) {
            price[j + 1] = price[j];
            j--;
        }
        price[j + 1] = key; 
    }

    cout << "\n Sorted Fares (Lowest to Highest) \n";
    for (int i = 0; i < n; i++) {
        cout << "Rs." << price[i] << "  ";
    }
    cout << endl;

    return 0;
}