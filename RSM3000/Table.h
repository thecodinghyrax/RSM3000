#pragma once
#include "SeatingGroup.h"
class Table :
    public SeatingGroup
{

public:
	Table();
	Table(int tableNumber);
	Table(int tableNumber, int capacity);
	~Table();

	void setTableNumber(int tableNumber);
	int getTableNumber();

	void setCapacity(int capacity);
	int getCapacity();

	void setTimeSeated(std::string time);
	std::string getTimeSeated();

	void setOccupied(bool occupied);
	bool getOccupied();

	void setDiners(int number);
	bool getDiners();

    std::string getSeatingType();
};

