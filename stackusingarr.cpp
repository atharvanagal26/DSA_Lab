#include<iostream>
using namespace std;
int stack[5];
int top = -1;

void push ()
{
    int value;

    if (top == 4)
    {
        cout<<"Stack is overflow"<<endl;
    } else {
        cout<<"Enter a value : "<<endl;
        cin>>value;

        top++;
        stack[top] = value;
        cout<<value<<" pushed"<<endl;
    }
}

void pop()
{
    if(top == -1)
    {
        cout<<"Stack is underflow"<<endl;
    } else {
        cout<<stack[top] <<" popped"<<endl;
        top --;
    }
}

void peek()
{
    if(top == -1)
    {
        cout<<"Stack is empty "<<endl;
    }else{
        cout<<"Top element : "<<stack[top]<<endl;
    }
}

void display()
{
    if (top == -1)
    {
        cout<<"Stack is empty"<<endl;
    } else {
        cout<<"Stack elements :";
        for (int i = top; i >= 0; i--)
        {
            cout<<stack[i]<<" ";
        }
        cout<<endl;
    }
}

int main ()
{
    int choice;
    do
    {
        cout<<"Stack Menu"<<endl;
        cout<<"1. Push"<<endl;
        cout<<"2. Pop"<<endl;
        cout<<"3. Peek"<<endl;
        cout<<"4. Display"<<endl;
        cout<<"5. Exit"<<endl;

        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                cout<<"Exit";
                break;
            
            default:
                cout<<"Invalid choice";
        }
    } while (choice != 5);
    return 0;
}

