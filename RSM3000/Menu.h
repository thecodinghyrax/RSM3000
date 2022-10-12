#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include "SeatingGroup.h"
#include "WaitingArea.h"

class Menu
{
private:
	std::list<std::string> waiting;
	std::string prefType;
	//std::string name;
	//int getSeatingRec(std::vector<SeatingGroup*> seating, std::string, int);
	//int getNumOpenSeating(std::vector<SeatingGroup*>);
	//static void removeFromBar(SeatingGroup&);
	//static int getNumOpenSeating(std::vector<SeatingGroup*>& seating);
	//static int getSeatingRec(std::vector<SeatingGroup*>&, std::string, int);
public:
	static void seatParty(std::vector<SeatingGroup*>&, std::list<std::string>&);
	static void viewWaiting(std::list<std::string>&);
	static void addToWaiting(std::list<std::string>&);
	static void removeWaiting(std::list<std::string>&);
	static void removeDiners(std::vector<SeatingGroup*>&);
	static void createSeatingConfig(std::vector<SeatingGroup*>&);
	static void currentOccupancy(std::vector<SeatingGroup*>&);
};

