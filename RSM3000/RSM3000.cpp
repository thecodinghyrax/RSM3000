#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "SeatingGroup.h"
#include "Bar.cpp"
#include "Booth.cpp"
#include "Table.cpp"

using namespace std;

int getSeatingRec(vector<SeatingGroup*> seating, string seatingType, int partySize);

int main()
{
    string input;
    vector<SeatingGroup*> seating;
    Booth b = Booth();

    // Default seating for testing
    seating.push_back(&b);
    //seating.push_back(make_unique<Booth>(200));
    //seating.push_back(make_unique<Booth>(205,4));

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

            int tableIndex = getSeatingRec(seating, "booth", 6);
            int tableNumber = seating[tableIndex]->getTableNumber();

            cout << "The party should be seated at table " << tableNumber << ". Enter Y to confirm, or N to manually select a table: ";
            cin >> input;
            while (input != "y" && input != "Y" && input != "n" && input != "N"){
                cout << "Invalid input. Please enter Y to confirm table " << tableNumber << ", or N to manually select a table: ";
                cin >> input;
            }
            if (input == "y" || input == "Y"){
                seating[tableIndex]->setOccupied(true);
                cout << "Party sucessfully seated at table " << tableNumber << endl;
                //TODO: Change table's status to occupied
            }
            if (input == "n" || input == "N"){
                //TODO: List available tables and allow user to select one
            }
        }

    }
}

int getSeatingRec(vector<SeatingGroup*> seating, string seatingType, int partySize){
    int match = -1;
    int count = 0;
    // First phase, checks for perfect match
    for (auto& s: seating){
        if (!s->getOccupied() && s->getCapacity() == partySize && s->getSeatingType() == seatingType){
            match = count;
        }
        count++;
    }

    // Second phase, checks for same type but larger capacity than party size
    return match;
}
