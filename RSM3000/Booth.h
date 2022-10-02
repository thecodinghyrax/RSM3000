#pragma once
#include "SeatingGroup.h"
class Booth :
    public SeatingGroup
{
//private:
//	int _capacity;
//	int _seatingSection;
//	std::string _timeSeated;
//	bool _occupied;
public:
	Booth();
	Booth(int tableNumber);
	Booth(int tableNumber, int capacity);
	~Booth();

	void setTableNumber(int tableNumber) override;
	int getTableNumber() override;

	void setCapacity(int capacity) override;
	int getCapacity() override;

	void setTimeSeated(std::string time) override;
	std::string getTimeSeated() override;

	void setOccupied(bool occupied) override;
	bool getOccupied() override;

	void setDiners(int number) override;
	bool getDiners();

    std::string getSeatingType();
};

