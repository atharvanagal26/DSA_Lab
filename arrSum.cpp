#include<iostream>
using namespace std;
int main () {
    int n;
    cout<<"Entre no of elements in array :";
    cin>> n;

    double arr[n], sum = 0.0;

    cout<<"Enter the elements of the array: \n";
    for (int i = 0; i < n ; i++){
        cout<<"Elements "<<i+1<<": "<<endl;
        cin>> arr[i];
        sum += arr[i];
    }

    double average = sum / n;
    cout<<"The avg of the array elements is :" <<average;
    return 0;
}