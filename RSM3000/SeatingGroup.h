#include <string>
#pragma once
class SeatingGroup
{
private:
	int _capacity;
	int _seatingSection;
	std::string _timeSeated;
	bool _occupied;
public:
	virtual void setCapacity(int _capacity) = 0;
	virtual int getCapacity() = 0;

	virtual void setSection(int _section) = 0;
	virtual int getSection() = 0;

	virtual void setTimeSeated() = 0;
	virtual std::string getTimeSeated() = 0;

	virtual void setOccupied() = 0;
	virtual bool getOccupied() = 0;
};

