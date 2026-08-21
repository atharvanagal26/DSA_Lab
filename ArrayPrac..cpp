#include<iostream>
using namespace std;

int main () {
    int n;
    cout << "Enter no of elements in array : ";
    cin >> n;
    int arr[n];

    cout << "Enter the elements of the array: \n";
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "\nThe elements of the array are:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl; 

// Insertion

    int val,pos;
    cout<<"Enter element: ";
    cin>>val;
    cout<<"Enter Position: ";
    cin>>pos;

    for(int i = n; i>=pos-1; i--){
        arr[i] = arr[i-1];
    }

    arr[pos-1] = val; 
    n++;

    cout<<"\n Array after Insertion: \n";
    for (int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    // Deletion

    int delpos;
    cout<<"Enter a position to delete : ";
    cin>>delpos;
    int deletedval = arr[delpos - 1];
    for (int i = delpos - 1; i < n - 1;i++){
        arr[i] = arr[i+1];
    }
    n--;

    cout << "Deleted element: " << deletedval << endl;
        cout << "\nArray after Deletion:\n";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    return 0;
}

