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
#include "CSVReader.h"

using namespace std;


int main()
{
    vector<SeatingGroup*> seating;
    list<string> waiting;
    string input;

    cout << "Restaurant Seating Manager 3000 Menu" << endl;

    while (input != "10"){
        cout << endl <<"1. Seat a party" << endl;
        cout << "2. View waiting area" << endl;
        cout << "3. Enter party into waiting area" << endl;
        cout << "4. Remove first party from waiting area" << endl;
        cout << "5. Remove Diners (clear a booth, table or bar seat)" << endl;
        cout << "6. Set Seating Capacity" << endl;
        cout << "7. Check Occupancy of Resturant" << endl;
        cout << "8. Load a previous seating configuration" << endl;
        cout << "9. Save the current seating configuration" << endl;
        cout << "10. Quit" << endl;

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
        else if (input == "5") {
            Menu::removeDiners(seating);
        }
        else if (input == "6") {
            Menu::createSeatingConfig(seating);
        }
        else if (input == "7") {
            Menu::currentOccupancy(seating);
        }
        else if (input == "8") {
            CSVReader::chooseLoader(seating);
        }
        else if (input == "9") {
            CSVReader::createCSV(seating);
        }

    }
}



