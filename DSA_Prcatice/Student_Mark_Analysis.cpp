#include <iostream>
using namespace std;
int main()
{
    int marks[5];
    int total = 0;
    int highest, lowest;
    float average;

    cout << "Enter marks of 5 subjects:" << endl;

    for(int i = 0; i < 5; i++)
    {
        cout << "Subject " << i+1 << ": ";
        cin >> marks[i];
        total = total + marks[i];
    }

    highest = marks[0];
    lowest = marks[0];

    for(int i = 1; i < 5; i++)
    {
        if(marks[i] > highest)
        {
            highest = marks[i];
        }

        if(marks[i] < lowest)
        {
            lowest = marks[i];
        }
    }

    average = total / 5.0;

    cout << "\nStudent Mark Analysis" << endl;
    cout << "Total Marks = " << total << endl;
    cout << "Average Marks = " << average << endl;
    cout << "Highest Marks = " << highest << endl;
    cout << "Lowest Marks = " << lowest << endl;

    return 0;
}