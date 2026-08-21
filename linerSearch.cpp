#include<iostream>
using namespace std;
int main () {
    int n;
    cout<<"Enter size of array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter "<<n<<" elements: ";
    for(int i=0; i<n; i++){
        cin>> arr[i];
    }

    int target;
    cout<<"Enter number to search: ";
    cin>> target;

    bool found = false;
    int position = -1;

    for (int i=0; i<n; i++){
        if(arr[i] == target ){
            found = true;
            position = i;
            break;
        }
    }

    if(found){
        cout<<target<<" is present in the array at position "<<position+1<<endl;
    } else {
        cout<<target<<" is not present in the array"<<endl;
    }

    return 0;
}