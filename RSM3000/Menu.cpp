#include "Menu.h"

/**************************************************************
* Method Name: getSeatingRec
* Description: Returns the index number of a seating object based 
*               on the input seating type and party size
* Input: vector<SeatingGroup*>/all configured seats, string/seat type, int/size of party
* Output: int/index of the recommended seating group 
***************************************************************/
int getSeatingRec(std::vector<SeatingGroup*>& seating, std::string seatingType, int partySize) {
    int match = -1;
    int count = 0;
    // Skip to phase 3 for no preference
    if (seatingType != "np") {
        // First phase, checks for perfect match
        for (auto& s : seating) {
            if (s->partyWillFit(partySize) && !s->getOccupied() && s->getCapacity() == partySize && s->getSeatingType() == seatingType) {
                match = count;
            }
            count++;
        }
        if (match > -1) {
            return match;
        }
        // Second phase, checks for same type but larger capacity than party size
        count = 0;
        for (auto& s : seating) {
            if (s->partyWillFit(partySize) && !s->getOccupied() && s->getCapacity() > partySize && s->getSeatingType() == seatingType) {
                match = count;
            }
            count++;
        }
        if (match > -1) {
            return match;
        }
    }
    // Third phase, find table of different type of same capacity
    count = 0;
    for (auto& s : seating) {
        if (s->partyWillFit(partySize) && !s->getOccupied() && s->getCapacity() == partySize) {
            match = count;
        }
        count++;
    }
    if (match > -1) {
        return match;
    }
    // Fourth phase, find table of any type and larger capacity
    count = 0;
    for (auto& s : seating) {
        if (s->partyWillFit(partySize) && !s->getOccupied() && s->getCapacity() > partySize) {
            match = count;
        }
        count++;
    }
    if (match > -1) {
        return match;
    }

    // If no tables found returns -1
    return match;
};

/**************************************************************
* Method Name: getNumOpenSeating
* Description: Counts and returns the number of unoccupied tables
* Input: vector<SeatingGroup*>/all configured seats
* Output: int/number of open tables
***************************************************************/
int getNumOpenSeating(std::vector<SeatingGroup*>& seating) {
    int numOpen = 0;
    for (auto& s : seating) {
        if (!s->getOccupied()) {
            numOpen++;
        }
    }
    return numOpen;
}

/**************************************************************
* Method Name: removeFromBar
* Description: Prompts the user for a number of diners to 
*               remove from the bar and removes them
* Input: SeatingGroup/a bar seating group
* Output: none
***************************************************************/
void removeFromBar(SeatingGroup& bar) {
    bool valid = false;
    while (!valid) {
        int dinersToRemove = SeatingGroup::promptForInt("a number of diners to remove", false);
        if (dinersToRemove > 0 && dinersToRemove <= bar.getDiners()) {
            bar.setDiners((bar.getDiners() - dinersToRemove));
            valid = true;
        }
        else {
            std::cout << "That is an invalid number to remove. Currently there are " << bar.getDiners() << " seated at the bar" << std::endl;
        }
    }

};

/**************************************************************
* Method Name: seatParty
* Description: Handles the gathering of party info, recommend a seat
*               based on preference. Allows for manually assigning to a
*               seat and offer to assign the party to the waiting area if
*               there is no room. 
* Input: vector<SeatingGroup*>/all configured seats, list<string>/current waiting room
* Output: none
***************************************************************/
void Menu::seatParty(std::vector<SeatingGroup*>& seating, std::list<std::string>& waiting) { // Option 1
    int partySize = SeatingGroup::promptForInt("party size", false);
    std::string prefType = SeatingGroup::promptForSeatType();
    std::string input;
    std::string name;
    int tableIndex = getSeatingRec(seating, prefType, partySize);

    if (tableIndex > -1) {
        int tableNumber = seating[tableIndex]->getTableNumber();
        std::string tableType = seating[tableIndex]->getSeatingType();

        std::cout << "The party should be seated at " << tableType << " " << tableNumber << ". Enter Y to confirm, or N to manually select a table: ";
        std::cin >> input;
        while (tolower(input[0]) != 'y' && tolower(input[0]) != 'n') {
            std::cout << "Invalid input. Please enter Y to confirm table " << tableNumber << ", or N to manually select a table: ";
            std::cin >> input;
        }
        if (tolower(input[0]) == 'y') {
            //seating[tableIndex]->setOccupied(true);
            if (seating[tableIndex]->partyWillFit(partySize)){
                seating[tableIndex]->setDiners(partySize + seating[tableIndex]->getDiners());
                std::cout << "Party sucessfully seated at " << tableType << " " << tableNumber << std::endl;
            } else {
                std::cout << "Party was too big to seat at this table." << std::endl;
            }

        }
        if (tolower(input[0]) == 'n') {
            // Check if there are open seats, if not go back to the menu
            if (getNumOpenSeating(seating) > 0) {
                std::cout << "All availiable tables: " << std::endl;
                int count = 0;
                // List each table and its index
                for (auto& s : seating) {
                    if (s->partyWillFit(partySize) && !s->getOccupied()) {
                        std::cout << count << ". " << s->getSeatingType() << " " << s->getTableNumber() <<
                            ", seats " << s->getCapacity() << std::endl;
                    }
                    count++;
                }
                bool validInput = false;
                std::cout << "Select an option (-1 to exit): ";
                while (!validInput) {
                    std::cin >> input;
                    try {
                        tableIndex = stoi(input);
                        // Validate index input
                        if (tableIndex == -1) {
                            validInput = true;
                        }
                        else if (seating[tableIndex]->getCapacity() < partySize) {
                            std::cout << std::endl << std::endl << "Party is larger than the selected seating area. Please try again." << std::endl;
                        }
                        else if (tableIndex >= 0) {
                            validInput = true;
                        }
                        else {
                            std::cout << "Invalid input, please re-enter: ";
                        }
                    }
                    catch (...) {
                        std::cout << "Invalid input, please re-enter: ";
                    }
                }
                if (tableIndex == -1) {
                    std::cout << "Returning to the main menu." << std::endl;
                }
                else if (seating[tableIndex]->getCapacity() < partySize) {
                    std::cout << "Party size is too large for this seating area." << std::endl;
                }
                else {
                    seating[tableIndex]->setDiners(partySize + seating[tableIndex]->getDiners());
                    std::cout << "Party sucessfully seated at " << tableType << " " << seating[tableIndex]->getTableNumber() << std::endl;
                }
            }
            else { // If getNumOpenSeating is 0
                std::cout << "All tables are currently occupied." << std::endl;

                std::cout << "Enter the party into the waiting area? [y = yes, n = no]: ";
                std::cin >> input;
                while (input != "y" && input != "Y" && input != "n" && input != "N") {
                    std::cout << "Invalid input. Enter the party into the waiting area? [y = yes, n = no]: ";
                    std::cin >> input;
                }

                if (tolower(input[0]) == 'y') {
                    name = WaitingArea::promptForName();
                    std::string pSize = std::to_string(partySize);
                    std::string fullString = "Party Name: " + name + ", Party Size: " + pSize;

                    waiting.push_back(fullString);

                    std::cout << "Successfully placed party in waiting area" << std::endl;
                }
            }
        }
    }
    else { // No tables found, send back to menu to re-enter party or clear tables
        std::cout << "No tables found, party size might be too big or the restaurant is full." << std::endl;
    }

};

/**************************************************************
* Method Name: viewWaiting
* Description: Displays all parties currently in the waiting area
* Input: list<string>/current waiting room
* Output: none
***************************************************************/
void Menu::viewWaiting(std::list<std::string>& waiting) { // Option 2
    std::cout << waiting.size() << std::endl;
    int counter = 1;
    std::cout << std::endl;
    for (auto const& n : waiting) {
        std::cout << counter << ". " << n << std::endl;
        counter++;
    }
    std::cout << std::endl;
};

/**************************************************************
* Method Name: addToWaiting
* Description: Prompts for party information and add them to a waiting queue
* Input: list<string>/current waiting room
* Output: none
***************************************************************/
void Menu::addToWaiting(std::list<std::string>& waiting) { // Option 3 
    std::string name = WaitingArea::promptForName();
    int partySize = SeatingGroup::promptForInt("party size", false);
    std::string pSize = std::to_string(partySize);
    std::string fullString = "Party Name: " + name + ", Party Size: " + pSize;

    waiting.push_back(fullString);

    std::cout << "Successfully placed party in waiting area" << std::endl;
};

/**************************************************************
* Method Name: removeWaiting
* Description: Removes the front party from the waiting queue and 
*               displays thier info so they can be called and seated.
* Input: list<string>/current waiting room
* Output: none
***************************************************************/
void Menu::removeWaiting(std::list<std::string>& waiting) { // Option 4
    if (!waiting.empty()) {

        std::cout << waiting.front() << " is now ready to be seated." << std::endl;
        waiting.pop_front();
    }
    else {
        std::cout << "Waiting area is empty" << std::endl;
    }
};

/**************************************************************
* Method Name: removeDiners
* Description: Displays a full list of all seating groups that are 
*               occupied and lets the user select one to clear. Clearing
*               the seating group frees it up to be reassigned to a new party.
* Input: vector<SeatingGroup*>/all configured seats
* Output: none
***************************************************************/
void Menu::removeDiners(std::vector<SeatingGroup*>& seating) { // Option 5
    bool anyOccupied = false;
    bool removed = false;
    int seatSelection;
    std::cout << "What would you like to clear? (-1 to exit)" << std::endl;
    for (int i = 0; i < seating.size(); ++i) {
        if (seating.at(i)->getOccupied() == 1 ||
            (seating.at(i)->getSeatingType() == "bar" && seating.at(i)->getDiners() > 0)) { // bar is not occupied until full
            std::cout << seating.at(i)->getTableNumber() << " - ";
            std::cout << seating.at(i)->getSeatingType() << " - ";
            std::cout << seating.at(i)->getDiners() << " diners" << std::endl;
            anyOccupied = true;
        }
    }
    if (!anyOccupied) {
        std::cout << std::endl << "No diners have been seated yet." << std::endl << std::endl;
    }
    else
    {
        std::cout << std::endl;
        seatSelection = SeatingGroup::promptForInt("seat number", true);

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
                std::cout << std::endl << "Exiting to main menu" << std::endl << std::endl;
            }
            else {
                std::cout << std::endl << "That was not a valid seating number." << std::endl << std::endl;
            }

        }
        else {
            std::cout << std::endl << "Seat " << seatSelection << " has been cleared." << std::endl << std::endl;
        }

    }
};

/**************************************************************
* Method Name: createSeatingConfig
* Description: 
* Input: vector<SeatingGroup*>/all configured seats
* Output: none
***************************************************************/
void Menu::createSeatingConfig(std::vector<SeatingGroup*>&) {
    throw "Not implemented";
    /*
    // This was Jaeydons attempt at implementing this feature. It will not compile so it was commented out. 
     int tables;
    int tableSeating;
    int  booths;
    int boothSeating;
    int barSeating;
    int barTables;
    int  totalCapacity;

    std::cout<<"Enter amount of Tables available"<<std::endl;
    tables = Table::setTableNumber(int& tableNumber){
        std::cin>>tableNumber;
    }  
        std::cout<<endl;

    std::cout<<"Enter amount of seating available at each Table"<<std::endl;
     tableSeating = Table::setCapacity(int& capacity){
        std::cin>>capacity; }
        std::cout<<endl;


    std::cout<<"Enter amount of Booths available"<<std::endl;
        booths = Booth::setTableNumber(int& tableNumber){
    std::cin>>tableNumber; }
        std::cout<<endl;


    std::cout<<"Enter amount of seating avaiable in each Booth"<<std::endl;
    boothSeating = Booth::setCapacity(int& capacity){
      std::cin>>capacity;  }
    std::cout<<endl;


    std::cout<<"Enter amount of Tables available at the Bar"<<std::endl;
    barTables = Bar::tableNumber(int& tableNumber){
        std::cin>>tableNumber; }
        std::cout<<endl;

    barSeating = Bar::setCapacity(int& capacity){
    std::cin>>capacity}
    std::cout<<std::endl;

    tableSeating = tables*tableSeating;

    boothSeating = booths*boothSeating;

    std::cout<<"Total Capacity with all Tables: "<<Table::getCapacity()<<endl;
    std::cout<<"Total Capacity with all Booths: "<<Booth::getCapacity<<endl;
    std::cout<<"Total Bar Capacity: "<<Bar::getCapacity()<<endl;
    std::cout<<std::endl;

    totalCapacity = tableSeating + boothSeating + barSeating;
    cout<<"Total Resturant Seating Capacity: "<<totalCapacity<<endl;
    */
};

/**************************************************************
* Method Name: currentOccupancy
* Description: 
* Input: vector<SeatingGroup*>/all configured seats
* Output: none
***************************************************************/
void Menu::currentOccupancy(std::vector<SeatingGroup*>&) {
    throw "Not implemented";
    /*
    * // This was some code Jaeydon was using to implement this feature. We had no time to test this so it was commented out. 
         bool anyOccupied = false;
     for (int i = 0; i < seating.size(); ++i) {
        if (seating.at(i)->getOccupied() == 1 ||
            (seating.at(i)->getSeatingType() == "bar" && seating.at(i)->getDiners() > 0)) { 
            std::cout << seating.at(i)->getTableNumber() << " - ";
            std::cout << seating.at(i)->getSeatingType() << " - ";
            std::cout << seating.at(i)->getDiners() << " diners" << std::endl;
            anyOccupied = true;

             if (!anyOccupied) {
        std::cout << std::endl << "No Tables Currently Occupied" << std::endl << std::endl;
    */
};

