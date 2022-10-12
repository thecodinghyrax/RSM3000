#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <array>
#include <algorithm>
#include "SeatingGroup.h"
#include "Booth.h"
#include "Bar.h"
#include "Table.h"

class CSVReader {
public:
	static void createCSV(std::vector<SeatingGroup*> &mainVector);
	static void readCSV(std::vector<SeatingGroup*> &mainVector);
};