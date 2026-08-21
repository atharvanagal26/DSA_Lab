#include <iostream>
using namespace std;
int main()
{
    string name[10];
    int quantity[10];
    float price[10];

    int n, choice, search;
    
    cout << "Enter number of products: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cout << "\nEnter details of product " << i + 1 << endl;

        cout << "Product name: ";
        cin >> name[i];

        cout << "Quantity: ";
        cin >> quantity[i];

        cout << "Price: ";
        cin >> price[i];
    }

    do
    {
        cout << "\nInventory Management System" << endl;
        cout << "1. Display Inventory" << endl;
        cout << "2. Search Product" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "\nProduct Details:" << endl;

                for(int i = 0; i < n; i++)
                {
                    cout << "\nProduct " << i + 1 << endl;
                    cout << "Name: " << name[i] << endl;
                    cout << "Quantity: " << quantity[i] << endl;
                    cout << "Price: " << price[i] << endl;
                }
                break;

            case 2:
                cout << "Enter product number to search: ";
                cin >> search;

                if(search >= 1 && search <= n)
                {
                    int i = search - 1;

                    cout << "\nProduct Found!" << endl;
                    cout << "Name: " << name[i] << endl;
                    cout << "Quantity: " << quantity[i] << endl;
                    cout << "Price: " << price[i] << endl;
                }
                else
                {
                    cout << "Product not found!" << endl;
                }
                break;

            case 3:
                cout << "Thank You" << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while(choice != 3);

    return 0;
}