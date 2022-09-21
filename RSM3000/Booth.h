#pragma once
#include "SeatingGroup.h"
class Booth :
    public SeatingGroup
{
private:
	int _capacity;
	int _seatingSection;
	std::string _timeSeated;
	bool _occupied;
public:
	Booth();
	Booth(int _section);
	Booth(int _section, int _capacity);
	~Booth();

	void setCapacity(int _capacity);
	int getCapacity();

	void setSection(int _section);
	int getSection();

	void setTimeSeated();
	std::string getTimeSeated();

	void setOccupied();
	bool getOccupied();
};

