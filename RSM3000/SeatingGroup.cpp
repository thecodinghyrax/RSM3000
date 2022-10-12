#include "SeatingGroup.h"

int SeatingGroup::promptForInt(std::string itemName, bool quitOption) {
    int userTemp;
    bool validInput = false;

    while (!validInput) {
        std::cout << "Please enter a " << itemName << ": " << std::endl;
        std::cin >> userTemp;
        if (std::cin.fail()) { // User entered an invalid int
            std::cin.clear(); // Clear the failed cin state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the stream buffer to allow for new user input
            std::cout << "That is not a valid " << itemName << ". Please try again." << std::endl;
        }
        else {
            if (userTemp > 0) {
                validInput = true;
            // If quitOption is true, -1 is a valid input in order to quit the current menu
            } else if (quitOption == true && userTemp == -1){
                return -1;
            }
            else {
                std::cout << "Must be greater than 0." << std::endl;
            }
        }
    }

    return userTemp;
}


std::string retrunTableType(char selection) {
    switch (tolower(selection)) {
    case 't':
        return "table";
        break;
    case 'b':
        return "booth";
        break;
    case 'r':
        return "bar";
        break;
    case 'n':
        return "np";
    default:
        return "invalid";
    }
}


std::string SeatingGroup::promptForSeatType() {
    char userInput;
    std::string tableType;
    bool valid = false;
    while (!valid) {
        std::cout << "Enter the preferred table type. T for table, B for booth, R for bar, or N for no preference: ";
        std::cin >> userInput;
        tableType = retrunTableType(userInput);
        if (tableType != "invalid") {
            valid = true;
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "That was not a valid selection. please try again." << std::endl;
        }
    }
    return tableType;

}
