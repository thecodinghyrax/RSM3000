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
#include "Menu.h"

using namespace std;


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

        if (input == "1") {
            Menu::seatParty(seating, waiting);
        }
        else if (input == "2") {
            Menu::viewWaiting(waiting);
        }
        else if (input == "3") {
            Menu::addToWaiting(waiting);
        }
        else if (input == "4") {
            Menu::removeWaiting(waiting);
        }
        // Remove diners from seats
        else if (input == "5") {
            Menu::removeDiners(seating);
        }
        else if (input == "6") {
            Menu::createSeatingConfig(seating);
        }
        else if (input == "7") {
            Menu::currentOccupancy(seating);
        }

    }
}



