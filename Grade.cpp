#include<iostream>
using namespace std;
int main () {
    int marks[5];
    int total_marks = 0;
    float aggregate;
    bool passed = true;
    for (int i=1 ; i<= 5; i++){
        cout<<"Entre your marks for course "<<i+1<<": ";
        cin>>marks[i];
        total_marks += marks[i]; 

        if (marks[i] < 40){
            passed = false;
        }
    }
    aggregate = (total_marks/500) * 100;

    cout<<"Total Marks : "<<total_marks<<endl;
    cout<<"Aggregate :" <<aggregate;
}