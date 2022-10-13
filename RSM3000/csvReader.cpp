#include "CSVReader.h"

/**************************************************************
* Method Name: createCSV
* Description:  Validation method that prompts the user for a
*               char representing a seating group. Reprompts if invalid.
* Input: vector<SeatingGroup>/the main seating configuration
* Output: string/the name of the seating group
***************************************************************/
void CSVReader::createCSV(std::vector<SeatingGroup*> &mainVector){
    std::string filePath;

    std::cout << "Please enter file name" << std::endl;
    std::cin >> filePath;

    filePath += ".csv";

    std::fstream myCSV;    
    myCSV.open(filePath, std::ios::out | std::ios::app);

    //checks for valid file
    while(!myCSV.is_open()){
        std::cout << "Filepath error, enter new Filepath" << std::endl;
        std::cin >> filePath;
        myCSV.open(filePath);
    }

    for (int i = 0; i < mainVector.size(); i++){
        myCSV << mainVector[i]->getSeatingType() << "," << mainVector[i]->getTableNumber() << "," << mainVector[i]->getCapacity() << std::endl;
    }
}

/**************************************************************
* Method Name: readCSV
* Description:  Validation method that prompts the user for a
*               char representing a seating group. Reprompts if invalid.
* Input: none
* Output: string/the name of the seating group
***************************************************************/
void CSVReader::readCSV(std::vector<SeatingGroup*> &mainVector){
    std::vector<std::array<std::string, 3>>tables;
    std::string filePath;
    std::string line;
    std::string temp;

    std::cout << "Please enter file name" << std::endl;
    std::cin >> filePath;

    std::fstream myCSV;    
    myCSV.open(filePath, std::ios::in);

    //checks for valid file
    while(!myCSV.is_open()){
        std::cout << "Filepath error, enter new Filepath" << std::endl;
        std::cin >> filePath;
        myCSV.open(filePath);
    }

    int column = 3; //Seating group, table no, table capacity
    int y = 0;
    int x = 0;

    while(getline(myCSV, line)){
        //skips empty line
        if (line == ""){}
        else{
            x=0;
            //Makes last element in row usable
            line = line + ",";
            std::array<std::string, 3> rows = {};
            for (int i=0; i < line.length(); i++){
                //if the character isn't a quotation mark or comma it's added to temporary variable
                if (line[i] != ',' && line[i] !='\"'){
                    temp += line[i];
                }
                //if character is quotation mark, ignore
                else if (line[i] == '\"'){}
                //if character is comma add element to array
                else{
                    rows[x] = temp;
                    temp = "";
                    x++;
                }
            }
            //add array to vector
            tables.push_back(rows);
            y++;
        }
    }

    //Creates new seating group object
    for(int i = 0; i < tables.size(); i++){
        if (tables[i][0][0] == 'b') {
            mainVector.push_back(new Booth(stoi(tables[i][1]), stoi(tables[i][2])));   
        }
        else if (tables[i][0][0] == 'r') {
            mainVector.push_back(new Bar(stoi(tables[i][1]), stoi(tables[i][2])));  
        }
        else if (tables[i][0][0] == 't') {
            mainVector.push_back(new Table(stoi(tables[i][1]), stoi(tables[i][2])));  
        }
    }
}

/**************************************************************
* Method Name: chooseLoader
* Description:  Validation method that prompts the user for a
*               char representing a seating group. Reprompts if invalid.
* Input: none
* Output: string/the name of the seating group
***************************************************************/
void CSVReader::chooseLoader(std::vector<SeatingGroup*>& mainVector) {
    int selection;
    bool valid = false;
    while (!valid) {
        std::cout << "Would you like to load the seating configuration from a CSV file (enter 1), an ASCII image (enter 2), or -1 to quit: " << std::endl;
        selection = SeatingGroup::promptForInt("loader", true);
        if (selection == 1) {
            valid = true;
            readCSV(mainVector);
        }
        else if (selection == 2) {
            valid = true;
            FileReader::readFile(mainVector);
        }
        else if (selection == -1) {
            valid = true;
            std::cout << "Exiting loader. No configuration was loaded." << std::endl;
        }
        else {
            std::cout << "That was not a valid option. Enter 1 for CSV, 2 for ASCII image or -1 to exit." << std::endl;

        }
    }
};
 