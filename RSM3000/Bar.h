#pragma once
#include "SeatingGroup.h"
class Bar :
	public SeatingGroup
{
public:
	Bar();
	Bar(int tableNumber);
	Bar(int tableNumber, int capacity);
	~Bar();

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

};
