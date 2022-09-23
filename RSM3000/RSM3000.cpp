#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input;

    cout << "Restaurant Seating Manager 3000 Menu" << endl;

    while (input != "9"){
        cout << "1. Seat a party" << endl;
        cout << "9. Quit" << endl;

        cout << endl << "Select an option: ";
        cin >> input;

        if (input == "1"){
            cout << "Enter the party size: ";
            cin >> input;
            //TODO: Validate input is an integer larger than 1
            cout << "Enter the preferred table type. T for table, B for booth, R for bar, or N for no preference: ";
            cin >> input;
            while (input != "t" && input != "T" && input != "b"
                   && input != "B" && input != "r" && input != "R"
                   && input != "n" && input != "N"){ //TODO: Better way to code this?
                cout << "Invalid input. Please enter T for table, B for booth, R for bar, or N for no preference: ";
                cin >> input;
            }
            //TODO: Function to determine the table
            int tableNumber = 1;
            cout << "The party should be seated at table " << tableNumber << ". Enter Y to confirm, or N to manually select a table: ";
            cin >> input;
            while (input != "y" && input != "Y" && input != "n" && input != "N"){
                cout << "Invalid input. Please enter Y to confirm table " << tableNumber << ", or N to manually select a table: ";
                cin >> input;
            }
            if (input == "y" || input == "Y"){
                cout << "Party sucessfully seated at table " << tableNumber << endl;
                //TODO: Change table's status to occupied
            }
            if (input == "n" || input == "N"){
                //TODO: List available tables and allow user to select one
            }
        }

    }
}
