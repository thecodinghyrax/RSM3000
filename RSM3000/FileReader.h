#pragma once
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

class FileReader {
public:
	static char findCapacity(std::string, int, int);
	static int getHighestSeatingNo(std::vector<SeatingGroup*>&);
	static void readFile(std::vector<SeatingGroup*>&);
};