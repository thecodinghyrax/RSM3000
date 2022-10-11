#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include "Booth.h"
#include "Bar.h"
#include "Table.h"
#include "SeatingGroup.h"

//searches characters up, down, left, and right of index to find capacity of seating group
char findCapacity(std::string stringToSearch, int startingIndex, int lineSize){
    lineSize+=1;
    //right
    if (startingIndex < stringToSearch.size()){
        if (isdigit(stringToSearch[startingIndex+1])){
            return stringToSearch[startingIndex+1];
        }
    }
    //left
    if (startingIndex > 0){
        if (isdigit(stringToSearch[startingIndex-1])){
            return stringToSearch[startingIndex-1];
        }
    }
    //down
    if (startingIndex + lineSize < stringToSearch.size()){
        if (isdigit(stringToSearch[startingIndex+lineSize])){
            return stringToSearch[startingIndex+lineSize];
        }
    }
    //up
    if (startingIndex-lineSize > 0){
        if (isdigit(stringToSearch[startingIndex-lineSize])){
            return stringToSearch[startingIndex-lineSize];
        }
    }
    //no capacity found
    std::cout << "fileSyntax Error. Seating group does not have capacity next to it" << std::endl;
    return '0';
}

//Finds highest table number in seating vector
int getHighestSeatingNo(std::vector<SeatingGroup*> seating){
    int maxNo = 0;
    for (auto& s: seating){
        if (s->getTableNumber() > maxNo){
            maxNo = s->getTableNumber();
        }
    }
    return maxNo;
}


std::vector<SeatingGroup *> readFile(std::vector<SeatingGroup*> vectorToAddTo){
    std::string filePath;
    std::string line;
    int barSeats = 0;
    int boothSeats = 0;
    int tableSeats = 0;
    int eatingSpaces = 0;
    std::cout << "Please enter file path" << std::endl;
    std::cin >> filePath;

    //opens file
    std::fstream myFile;
    myFile.open(filePath);

    //checks for valid file
    while(!myFile.is_open()){
        std::cout << "Filepath error, enter new Filepath" << std::endl;
        std::cin >> filePath;
        myFile.open(filePath);
    }

    int lineCount = 0;
    std::vector<std::vector<char>> paragraphVector = {};

    //counts number of chairs in seating groups
    while (getline (myFile, line)){
        std::vector<char> lineVector = {};

        for (int i = 0; i < line.size(); i++){
            lineVector.push_back(line[i]);
            if (isdigit(line[i])){
                eatingSpaces += 1;
            }
            switch (line[i]){
            case 'b':
                boothSeats += 1;
                break;
            case 'r':
               barSeats += 1;
                break;
            case 't':
                tableSeats += 1;
                break;
            default:
                break;
            }
        }
    paragraphVector.push_back(lineVector);
    }

    myFile.close();

    std::string outputString;

    //creates string from file
    for(int i = 0; i < paragraphVector.size(); i++){
        for (int j = 0; j < paragraphVector[i].size();j++){
            outputString += paragraphVector[i][j];
        }
        outputString += "\n";
    }

    // TODO - Can this be removed?
    //std::pair<char, int>seatingGroupData;

    std::vector<std::pair<char, char>>seatingGroupDataStorage;

    //creates vector that stores each seating group with type and capacity
    for (int i = 0; i < outputString.size(); i++){
        switch (outputString[i]){
            case 'b':
                // TODO - 'argument': conversion from 'size_t' to 'int', possible loss of data
                seatingGroupDataStorage.push_back(std::make_pair('b',findCapacity(outputString, i, line.size())));
                break;
            case 'r':
                // TODO - 'argument': conversion from 'size_t' to 'int', possible loss of data
                seatingGroupDataStorage.push_back(std::make_pair('r',findCapacity(outputString, i, line.size())));
                break;
            case 't':
                // TODO - 'argument': conversion from 'size_t' to 'int', possible loss of data
                seatingGroupDataStorage.push_back(std::make_pair('t',findCapacity(outputString, i, line.size())));
                break;
            default:
                break;
            }
    }
    //sorts seating groups
    std::sort(seatingGroupDataStorage.begin(), seatingGroupDataStorage.end());

    //TODO - Can these be removed?
    //int t1Count, t2Count, t3Count, t4Count, t5Count,  t6Count, t7Count, t8Count, t9Count,
    //r1Count, r2Count, r3Count, r4Count, r5Count,  r6Count, r7Count, r8Count, r9Count,
    //b1Count, b2Count, b3Count, b4Count, b5Count,  b6Count, b7Count, b8Count, b9Count = 0;

    //creates array to keep track of number of seating groups with the same capacity (ex. 2 tables of 4)
    std::array<std::pair<int, char>, 27>seatingGroupCount; //0-8 is booth, 9-17 is bar, 18-26 is table
    for (int i=0; i < seatingGroupCount.size(); i++){
        seatingGroupCount[i] = std::make_pair(0, '0');
    }

    //updates array based on seating groups stores
    for (int i = 0; i < seatingGroupDataStorage.size(); i++){
        //booth
        if (seatingGroupDataStorage[i].first == 'b'){
            switch (seatingGroupDataStorage[i].second-'0')
            {
            case 1: //booth of 1
                seatingGroupCount[0].first++;
                seatingGroupCount[0].second = seatingGroupDataStorage[i].second;
                break;
            case 2: //booth of 2
                seatingGroupCount[1].first++;
                seatingGroupCount[1].second = seatingGroupDataStorage[i].second;
                break;
            case 3: //booth of 3
                seatingGroupCount[2].first++;
                seatingGroupCount[2].second = seatingGroupDataStorage[i].second;
                break;
            case 4: //booth of 4
                seatingGroupCount[3].first++;
                seatingGroupCount[3].second = seatingGroupDataStorage[i].second;
                break;
            case 5: //booth of 5
                seatingGroupCount[4].first++;
                seatingGroupCount[4].second = seatingGroupDataStorage[i].second;
                break;
            case 6: //booth of 6
                seatingGroupCount[5].first++;
                seatingGroupCount[5].second = seatingGroupDataStorage[i].second;
                break;
            case 7: //booth of 7
                seatingGroupCount[6].first++;
                seatingGroupCount[6].second = seatingGroupDataStorage[i].second;
                break;
            case 8: //booth of 8
                seatingGroupCount[7].first++;
                seatingGroupCount[7].second = seatingGroupDataStorage[i].second;
                break;
            case 9: //booth of 9
                seatingGroupCount[8].first++;
                seatingGroupCount[8].second = seatingGroupDataStorage[i].second;
                break;
            default:
                break;
            }
        }
        //bar
        else if (seatingGroupDataStorage[i].first == 'r'){
            switch (seatingGroupDataStorage[i].second - '0'){
            case 1: //bar of 1
                seatingGroupCount[9].first++;
                seatingGroupCount[9].second = seatingGroupDataStorage[i].second;
                break;
            case 2: //bar of 2
                seatingGroupCount[10].first++;
                seatingGroupCount[10].second = seatingGroupDataStorage[i].second;
                break;
            case 3: //bar of 3
                seatingGroupCount[11].first++;
                seatingGroupCount[11].second = seatingGroupDataStorage[i].second;
                break;
            case 4: //bar of 4
                seatingGroupCount[12].first++;
                seatingGroupCount[12].second = seatingGroupDataStorage[i].second;
                break;
            case 5: //bar of 5
                seatingGroupCount[13].first++;
                seatingGroupCount[13].second = seatingGroupDataStorage[i].second;
                break;
            case 6: //bar of 6
                seatingGroupCount[14].first++;
                seatingGroupCount[14].second = seatingGroupDataStorage[i].second;
                break;
            case 7: //bar of 7
                seatingGroupCount[15].first++;
                seatingGroupCount[15].second = seatingGroupDataStorage[i].second;
                break;
            case 8: //bar of 8
                seatingGroupCount[16].first++;
                seatingGroupCount[16].second = seatingGroupDataStorage[i].second;
                break;
            case 9: //bar of 9
                seatingGroupCount[17].first++;
                seatingGroupCount[17].second = seatingGroupDataStorage[i].second;
                break;
            default:
                break;
            }
        }
        //table
        else if (seatingGroupDataStorage[i].first == 't'){
            switch (seatingGroupDataStorage[i].second - '0'){
            case 1: //table of 1
                seatingGroupCount[18].first++;
                seatingGroupCount[18].second = seatingGroupDataStorage[i].second;
                break;
            case 2: //table of 2
                seatingGroupCount[19].first++;
                seatingGroupCount[19].second = seatingGroupDataStorage[i].second;
                break;
            case 3: //table of 3
                seatingGroupCount[20].first++;
                seatingGroupCount[20].second = seatingGroupDataStorage[i].second;
                break;
            case 4: //table of 4
                seatingGroupCount[21].first++;
                seatingGroupCount[21].second = seatingGroupDataStorage[i].second;
                break;
            case 5: //table of 5
                seatingGroupCount[22].first++;
                seatingGroupCount[22].second = seatingGroupDataStorage[i].second;
                break;
            case 6: //table of 6
                seatingGroupCount[23].first++;
                seatingGroupCount[23].second = seatingGroupDataStorage[i].second;
                break;
            case 7: //table of 7
                seatingGroupCount[24].first++;
                seatingGroupCount[24].second = seatingGroupDataStorage[i].second;
                break;
            case 8: //table of 8
                seatingGroupCount[25].first++;
                seatingGroupCount[25].second = seatingGroupDataStorage[i].second;
                break;
            case 9: //table of 9
                seatingGroupCount[26].first++;
                seatingGroupCount[26].second = seatingGroupDataStorage[i].second;
                break;
            default:
                break;
            }
        }
    }

    //adds new seating groups from file to main seating vector
    for (int i = 0; i < seatingGroupCount.size(); i++){
        if (seatingGroupCount[i].second != '0'){
            int groups = seatingGroupCount[i].first / (seatingGroupCount[i].second-'0');
            if (i < 9){
                for (int j = 0; j < groups; j++){
                    vectorToAddTo.push_back(new Booth(getHighestSeatingNo(vectorToAddTo)+1, seatingGroupCount[i].second-'0'));
                }
            }
            else if (i < 18){
                for (int j = 0; j < groups; j++){
                    vectorToAddTo.push_back(new Bar(getHighestSeatingNo(vectorToAddTo)+1, seatingGroupCount[i].second-'0'));
                }
            }
            else {
                for (int j = 0; j < groups; j++){
                    vectorToAddTo.push_back(new Table(getHighestSeatingNo(vectorToAddTo)+1, seatingGroupCount[i].second-'0'));
                }
            }
        }
    }
    return std::vector<SeatingGroup*>{}; // TODO - this will need to be changed (a return is required)
}


