#include <iostream>
#include <string>
using namespace std;

int main()
{
    int productId[100];
    string productName[100];
    float price[100];

    int n, searchId;

    cout << "Enter number of products: ";
    cin >> n;

    cout << "\nEnter product details:\n";

    for (int i = 0; i < n; i++)
    {
        cout << "\nProduct " << i + 1 << endl;

        cout << "Enter Product ID: ";
        cin >> productId[i];

        cout << "Enter Product Name: ";
        cin >> productName[i];

        cout << "Enter Product Price: ";
        cin >> price[i];
    }

    cout << "\nEnter Product ID to search: ";
    cin >> searchId;

    int last = productId[n - 1];

    productId[n - 1] = searchId;

    int i = 0;
    while (productId[i] != searchId)
    {
        i++;
    }

    productId[n - 1] = last;

    if ((i < n - 1) || (last == searchId))
    {
        cout << "\n--- Product Found! ---\n";
        cout << "Product ID: " << productId[i] << endl;
        cout << "Product Name: " << productName[i] << endl;
        cout << "Product Price: Rs." << price[i] << endl;
    }
    else
    {
        cout << "\nProduct Not Available\n";
    }

    return 0;
}