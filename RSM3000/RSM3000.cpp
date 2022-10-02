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


    // Default seating for testing
    Booth b = Booth();
    Booth b2 = Booth(204,4);
    Booth b3 = Booth(205,5);
    Bar r1 = Bar(300,2);
    Bar r2 = Bar(301,3);
    Table t1 = Table(400);
    Table t2 = Table(401,6);
    Table t3 = Table(410,8);
    seating.push_back(&b);
    seating.push_back(&b2);
    seating.push_back(&b3);
    seating.push_back(&r1);
    seating.push_back(&r2);
    seating.push_back(&t1);
    seating.push_back(&t2);
    seating.push_back(&t3);

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
            int partySize = stoi(input);
            cout << "Enter the preferred table type. T for table, B for booth, R for bar, or N for no preference: ";
            cin >> input;
            while (input != "t" && input != "T" && input != "b"
                   && input != "B" && input != "r" && input != "R"
                   && input != "n" && input != "N"){ //TODO: Better way to code this?
                cout << "Invalid input. Please enter T for table, B for booth, R for bar, or N for no preference: ";
                cin >> input;
            }
            string prefType;
            if (input == "t" || input == "T"){
                prefType = "table";
            } else if (input == "b" || input == "B"){
                prefType = "booth";
            } else if (input == "r" || input == "R"){
                prefType = "bar";
            } else if (input == "n" || input == "N"){
                prefType = "np";
            }


            int tableIndex = getSeatingRec(seating, prefType, partySize);
            if (tableIndex > -1){
                int tableNumber = seating[tableIndex]->getTableNumber();
                string tableType = seating[tableIndex]->getSeatingType();

                cout << "The party should be seated at " << tableType << " " << tableNumber << ". Enter Y to confirm, or N to manually select a table: ";
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
            } else { // No tables found, send back to menu to re-enter party or clear tables
                cout << "No tables found, party size might be too big or the restaurant is full." << endl;
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
    if (match > -1){
        return match;
    }
    // Second phase, checks for same type but larger capacity than party size
    count = 0;
    for (auto& s: seating){
        if (!s->getOccupied() && s->getCapacity() > partySize && s->getSeatingType() == seatingType){
            match = count;
        }
        count++;
    }
    if (match > -1){
        return match;
    }
    // Third phase, find table of different type
    count = 0;
    for (auto& s: seating){
        if (!s->getOccupied() && s->getCapacity() > partySize){
            match = count;
        }
        count++;
    }
    if (match > -1){
        return match;
    }

    // If no tables found returns -1
    return match;
}
