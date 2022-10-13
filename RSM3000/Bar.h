#pragma once
#include "SeatingGroup.h"
class Bar :
	public SeatingGroup
{
private:
	void setCapacity(int capacity);
	void setOccupied(bool occupied);

public:
	Bar();
	Bar(int tableNumber);
	Bar(int tableNumber, int capacity);
	~Bar();

	void setTableNumber(int tableNumber);
	int getTableNumber();

	void setTimeSeated(std::string time);
	std::string getTimeSeated();

	void setDiners(int number);
	int getDiners();

    std::string getSeatingType();

	int getCapacity();

	bool getOccupied();

	void removeDiners();

	void removeDiners(int numDiners);
};
