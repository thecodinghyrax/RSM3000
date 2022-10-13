#include "SeatingGroup.h"


/**************************************************************
* Method Name: promptForInt
* Description:  Validation method that prompts a user for an
*               int by asking for an item. User will be reprompted
*               if the input is not valid. 
* Input: string/name of the item to select
*        bool/true if user can enter -1 to exit else false
* Output: int/selection number
***************************************************************/
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

/**************************************************************
* Method Name: returnTableType
* Description:  Conversion method that takes in a char and 
*               returns the corresponding seating type, or invalid
* Input: char/the letter that represents a seating group
* Output: string/the name of the seating group
***************************************************************/
std::string returnTableType(char selection) {
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

/**************************************************************
* Method Name: promptForSeatType
* Description:  Validation method that prompts the user for a 
*               char representing a seating group. Reprompts if invalid.
* Input: none
* Output: string/the name of the seating group
***************************************************************/
std::string SeatingGroup::promptForSeatType() {
    char userInput;
    std::string tableType;
    bool valid = false;
    while (!valid) {
        std::cout << "Enter the preferred table type. T for table, B for booth, R for bar, or N for no preference: ";
        std::cin >> userInput;
        tableType = returnTableType(userInput);
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

/**************************************************************
* Method Name: partyWillFit
* Description:  Validation method that checks if a party will fit 
*               in a certain seating group
* Input: int/size of the party
* Output: bool/true if the party will fit else false
***************************************************************/
bool SeatingGroup::partyWillFit(int partySize){
    return (_capacity - _numberOfDiners) >= partySize;
}
