#include <string>
#include <iostream>

#pragma once
class SeatingGroup
{
protected:
	int _tableNumber;
	int _capacity;
	int _numberOfDiners;
	std::string _timeSeated;
	bool _occupied;

	virtual void setOccupied(bool occupied) = 0;
	virtual void setCapacity(int capacity) = 0;

public:
	virtual void setTableNumber(int tableNumber) = 0;
	virtual int getTableNumber() = 0;

	virtual void setTimeSeated(std::string time) = 0;
	virtual std::string getTimeSeated() = 0;

	virtual void setDiners(int number) = 0;
	virtual int getDiners() = 0;

    virtual std::string getSeatingType() = 0;

	virtual int getCapacity() = 0;

	virtual bool getOccupied() = 0;

	virtual void removeDiners() = 0;

	static int promptForInt(std::string itemName);
	static std::string promptForSeatType();
};

