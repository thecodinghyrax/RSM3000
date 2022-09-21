#pragma once
#include "SeatingGroup.h"
class Bar :
    public SeatingGroup
{
private:
	int _capacity;
	int _seatingSection;
	std::string _timeSeated;
	bool _occupied;
public:
	Bar();
	Bar(int _section);
	Bar(int _section, int _capacity);
	~Bar();

	void setCapacity(int _capacity);
	int getCapacity();

	void setSection(int _section);
	int getSection();

	void setTimeSeated();
	std::string getTimeSeated();

	void setOccupied();
	bool getOccupied();
};

