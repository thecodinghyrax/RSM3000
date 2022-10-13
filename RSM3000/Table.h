#pragma once
#include "SeatingGroup.h"

class Table :
    public SeatingGroup
{
private:
	void setCapacity(int capacity);
	void setOccupied(bool occupied);

public:
	Table();
	Table(int tableNumber);
	Table(int tableNumber, int capacity);
	~Table();

	void setTableNumber(int tableNumber);
	int getTableNumber();

	void setTimeSeated(std::string time);
	std::string getTimeSeated();

	void setDiners(int number);
	int getDiners();

	int getCapacity();

	bool getOccupied();

    std::string getSeatingType();

	void removeDiners();
};

