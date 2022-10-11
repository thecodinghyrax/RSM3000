#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <list>
#include <iterator>
#include "SeatingGroup.h"
#include "Bar.h"
#include "Booth.h"
#include "Table.h"
#include "WaitingArea.h"

using namespace std;

int getSeatingRec(vector<SeatingGroup*> seating, string seatingType, int partySize);
int getNumOpenSeating (vector<SeatingGroup*> seating);
void removeFromBar(SeatingGroup& bar);

int main()
{
    string input;
    vector<SeatingGroup*> seating;
    list<string> waiting;
    int partySize = 0;
    std::string prefType;
    string name;


    // Default seating for testing
    Booth b = Booth();
    Booth b2 = Booth(204,4);
    Booth b3 = Booth(205,5);
    Bar r1 = Bar(300,30);
    Table t1 = Table(400);
    Table t2 = Table(401,6);
    Table t3 = Table(410,8);
    seating.push_back(&b);
    seating.push_back(&b2);
    seating.push_back(&b3);
    seating.push_back(&r1);
    seating.push_back(&t1);
    seating.push_back(&t2);
    seating.push_back(&t3);

    cout << "Restaurant Seating Manager 3000 Menu" << endl;

    while (input != "9"){
        cout << endl <<"1. Seat a party" << endl;
        cout << "2. View waiting area" << endl;
        cout << "3. Enter party into waiting area" << endl;
        cout << "4. Remove first party from waiting area" << endl;
        cout << "5. Remove Diners (clear a booth, table or bar seat)" << endl;
        cout << "6. Set Seating Capacity" << endl;
        cout << "7. Check Occupancy of Resturant" << endl;
        cout << "9. Quit" << endl;

        cout << endl << "Select an option: ";
        cin >> input;

        if (input == "1"){

            partySize = SeatingGroup::promptForInt("party size");

            prefType = SeatingGroup::promptForSeatType();

            int tableIndex = getSeatingRec(seating, prefType, partySize);
            if (tableIndex > -1){
                int tableNumber = seating[tableIndex]->getTableNumber();
                string tableType = seating[tableIndex]->getSeatingType();

                cout << "The party should be seated at " << tableType << " " << tableNumber << ". Enter Y to confirm, or N to manually select a table: ";
                cin >> input;
                while (tolower(input[0]) != 'y' && tolower(input[0]) != 'n') {
                    cout << "Invalid input. Please enter Y to confirm table " << tableNumber << ", or N to manually select a table: ";
                    cin >> input;
                }
                if (tolower(input[0]) == 'y') {
                    //seating[tableIndex]->setOccupied(true);
                    seating[tableIndex]->setDiners(partySize);
                    cout << "Party sucessfully seated at table " << tableNumber << endl;
                }
                if (tolower(input[0]) == 'n') {
                    // Check if there are open seats, if not go back to the menu
                    if (getNumOpenSeating(seating) > 0){
                        cout << "All availiable tables: " << endl;
                        int count = 0;
                        // List each table and its index
                        for (auto& s : seating){
                            if (!s->getOccupied()){
                                cout << count << ". " << s->getSeatingType() << " " << s->getTableNumber() <<
                                        ", seats " << s->getCapacity() << endl;
                            }
                            count++;
                        }
                        bool validInput = false;
                        cout << "Select an option (-1 to exit): ";
                        while (!validInput){
                            cin >> input;
                            try {
                                tableIndex = stoi(input);
                                // Validate index input
                                if (tableIndex == -1) {
                                    validInput = true;
                                }
                                else if (seating[tableIndex]->getCapacity() >= partySize) {
                                    cout << endl << endl << "Party is larger than the selected seating area. Please try again." << endl;
                                }
                                else if (tableIndex >= 0) {
                                    validInput = true;
                                } else {
                                    cout << "Invalid input, please re-enter: ";
                                }
                            } catch (exception e){
                                cout << "Invalid input, please re-enter: ";
                            }
                        }
                        if (tableIndex == -1) {
                            cout << "Returning to the main menu."<< endl;
                        }
                        else if (seating[tableIndex]->getCapacity() < partySize) {
                            cout << "Party size is too large for this seating area." << endl;
                        }
                        else {
                            seating[tableIndex]->setDiners(partySize);
                            cout << "Party sucessfully seated at table " << seating[tableIndex]->getTableNumber() << endl;
                        }
                    } else { // If getNumOpenSeating is 0
                        cout << "All tables are currently occupied." << endl;

                        cout << "Enter the party into the waiting area? [y = yes, n = no]: ";
                        cin >> input;
                        while (input != "y" && input != "Y" && input != "n" && input != "N"){
                            cout << "Invalid input. Enter the party into the waiting area? [y = yes, n = no]: ";
                            cin >> input;
                        }

                        if (tolower(input[0]) == 'y') {
                            name = WaitingArea::promptForName();
                            string pSize = to_string(partySize);
                            string fullString = "Party Name: " + name + ", Party Size: " + pSize;

                            waiting.push_back(fullString);

                            cout << "Successfully placed party in waiting area" << endl;
                        }
                    }
                }
            } else { // No tables found, send back to menu to re-enter party or clear tables
                cout << "No tables found, party size might be too big or the restaurant is full." << endl;
            }

        }
        else if (input == "2") {
            cout << "entering two" << endl;
            cout << waiting.size() << endl;
            int counter = 1;
            cout << endl;
            for (auto const &n : waiting) {
                cout << counter << ". " << n << endl;
                counter++;
            }
            cout << endl;
            cout << "leaving two" << endl;

        }
        else if (input == "3") {
            name = WaitingArea::promptForName();
            partySize = SeatingGroup::promptForInt("party size");
            string pSize = to_string(partySize);
            string fullString = "Party Name: " + name + ", Party Size: " + pSize;

            waiting.push_back(fullString);

            cout << "Successfully placed party in waiting area" << endl;
        }
        else if (input == "4") {
            if (!waiting.empty()) {

                cout << waiting.front() << " is now ready to be seated." << endl;
                waiting.pop_front();
            }
            else {
                cout << "Waiting area is empty" << endl;
            }
        }
        // Remove diners from seats
        else if (input == "5") {
            bool anyOccupied = false;
            bool removed = false;
            int seatSelection;
            cout << "What would you like to clear? (-1 to exit)" << endl;
            for (int i = 0; i < seating.size(); ++i) {
                if (seating.at(i)->getOccupied() == 1 || 
                    (seating.at(i)->getSeatingType() == "bar" && seating.at(i)->getDiners() > 0)) { // bar is not occupied until full
                    cout << seating.at(i)->getTableNumber() << " - ";
                    cout << seating.at(i)->getSeatingType() << " - ";
                    cout << seating.at(i)->getDiners() << " diners" << endl;
                    anyOccupied = true;
                }
            }
            if (!anyOccupied) {
                cout << endl << "No diners have been seated yet." << endl << endl;
            }
            else 
            {
                cout << endl;
                seatSelection = SeatingGroup::promptForInt("seat number");

                for (int i = 0; i < seating.size(); ++i) {
                    if (seating.at(i)->getTableNumber() == seatSelection) {
                        if (seating.at(i)->getSeatingType() == "bar") {
                            removeFromBar(*seating.at(i));
                        }
                        else {
                            seating.at(i)->setDiners(0);
                            removed = true;
                        }
                    }
                }
                if (!removed) {
                    if (seatSelection == -1) {
                        cout << endl << "Exiting to main menu" << endl << endl;
                    }
                    else {
                        cout << endl << "That was not a valid seating number." << endl << endl;
                    }

                }
                else {
                    cout << endl << "Seat " << seatSelection << " has been cleared." << endl << endl;
                }

            }
        }

    }
}

// Returns the index number of a seating object based on the input seating type and party size
int getSeatingRec(vector<SeatingGroup*> seating, string seatingType, int partySize){
    int match = -1;
    int count = 0;
    // Skip to phase 3 for no preference
    if (seatingType != "np"){
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
    }
    // Third phase, find table of different type of same capacity
    count = 0;
    for (auto& s: seating){
        if (!s->getOccupied() && s->getCapacity() == partySize){
            match = count;
        }
        count++;
    }
    if (match > -1){
        return match;
    }
    // Fourth phase, find table of any type and larger capacity
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

// Counts and returns the number of unoccupied tables
int getNumOpenSeating (vector<SeatingGroup*> seating){
    int numOpen = 0;
    for (auto& s : seating){
        if (!s->getOccupied()){
            numOpen++;
        }
    }
    return numOpen;
}

void removeFromBar(SeatingGroup& bar) {
    bool valid = false;
    while (!valid) {
        int dinersToRemove = SeatingGroup::promptForInt("a number of diners to remove");
        if (dinersToRemove > 0 && dinersToRemove <= bar.getDiners()) {
            bar.setDiners((bar.getDiners() - dinersToRemove));
            valid = true;
        }
        else {
            cout << "That is an invalid number to remove. Currently there are " << bar.getDiners() << " seated at the bar" << endl;
        }
    }

}
