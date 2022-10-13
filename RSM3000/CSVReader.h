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
#include "FileReader.h"

class CSVReader {
public:
	static void createCSV(std::vector<SeatingGroup*> &);
	static void readCSV(std::vector<SeatingGroup*> &);
	static void chooseLoader(std::vector<SeatingGroup*>& );
};