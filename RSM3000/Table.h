#pragma once
#include "SeatingGroup.h"
class Table :
    public SeatingGroup
{
private:
	int _capacity;
	int _seatingSection;
	std::string _timeSeated;
	bool _occupied;
public:
	Table();
	Table(int _section);
	Table(int _section, int _capacity);
	~Table();

	void setCapacity(int _capacity);
	int getCapacity();

	void setSection(int _section);
	int getSection();

	void setTimeSeated();
	std::string getTimeSeated();

	void setOccupied();
	bool getOccupied();
};

