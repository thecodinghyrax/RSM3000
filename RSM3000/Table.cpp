#include "Table.h"

// Private
void Table::setCapacity(int capacity) {
	_capacity = capacity;
};

void Table::setOccupied(bool occupied) {
	_occupied = occupied;
};


// Public
Table::Table() {
	setTableNumber(101);
	setCapacity(4);
	setDiners(0);
	setOccupied(false);
};
Table::Table(int tableNumber) {
	setTableNumber(tableNumber);
	setCapacity(4);
	setDiners(0);
	setOccupied(false);
};
Table::Table(int tableNumber, int capacity) {
	setTableNumber(tableNumber);
	setCapacity(capacity);
	setDiners(0);
	setOccupied(false);
};
Table::~Table() {
};

void Table::setTableNumber(int tableNumber) {
	_tableNumber = tableNumber;
};

int Table::getTableNumber() {
	return _tableNumber;
};

void Table::setTimeSeated(std::string time) {
	_timeSeated = time;
};

std::string Table::getTimeSeated() {
	return _timeSeated;
};

void Table::setDiners(int number) {
	_numberOfDiners = number;
	if (number == 0) {
		setOccupied(false);
	}
	else {
		setOccupied(true);
	}
};

int Table::getDiners() {
	return _numberOfDiners;
};

int Table::getCapacity() {
	return _capacity;
};

bool Table::getOccupied() {
	return _occupied;
};

std::string Table::getSeatingType(){
    return "table";
}

void Table::removeDiners() {
	setDiners(0);
	setOccupied(false);
};