#pragma once
#include "SeatingGroup.h"
class Booth :
    public SeatingGroup
{
private:
	void setCapacity(int capacity) override;
	void setOccupied(bool occupied) override;

public:
	Booth();
	Booth(int tableNumber);
	Booth(int tableNumber, int capacity);
	~Booth();

	void setTableNumber(int tableNumber) override;
	int getTableNumber() override;

	void setTimeSeated(std::string time) override;
	std::string getTimeSeated() override;

	void setDiners(int number) override;
	int getDiners();

	int getCapacity() override;

	bool getOccupied() override;

    std::string getSeatingType();

	void removeDiners();
};

