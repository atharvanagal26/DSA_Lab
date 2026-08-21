#include <iostream>
using namespace std;

int main()
{
    int seats[10] = {0};
    int choice, seatNo;

    do
    {
        cout << "\nMovie Ticket Booking System" << endl;
        cout << "1. Display Seats" << endl;
        cout << "2. Book Ticket" << endl;
        cout << "3. Cancel Ticket" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "\nSeat Status:" << endl;

                for(int i = 0; i < 10; i++)
                {
                    cout << "Seat " << i + 1 << ": ";

                    if(seats[i] == 0)
                        cout << "Available" << endl;
                    else
                        cout << "Booked" << endl;
                }
                break;

            case 2:
                cout << "Enter seat number to book (1-10): ";
                cin >> seatNo;

                if(seatNo < 1 || seatNo > 10)
                {
                    cout << "Invalid seat number!" << endl;
                }
                else if(seats[seatNo - 1] == 1)
                {
                    cout << "Seat is already booked!" << endl;
                }
                else
                {
                    seats[seatNo - 1] = 1;
                    cout << "Ticket booked successfully!" << endl;
                }
                break;

            case 3:
                cout << "Enter seat number to cancel (1-10): ";
                cin >> seatNo;

                if(seatNo < 1 || seatNo > 10)
                {
                    cout << "Invalid seat number!" << endl;
                }
                else if(seats[seatNo - 1] == 0)
                {
                    cout << "Seat is not booked!" << endl;
                }
                else
                {
                    seats[seatNo - 1] = 0;
                    cout << "Ticket cancelled successfully!" << endl;
                }
                break;

            case 4:
                cout << "Thank you!" << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while(choice != 4);

    return 0;
}