#include "Bar.h"

// Private

void Bar::setCapacity(int capacity) {
	_capacity = capacity;
};

void Bar::setOccupied(bool occupied) {
	_occupied = occupied;
};


// Public
Bar::Bar() {
	setTableNumber(301);
	setCapacity(30);
	setDiners(0);
	setOccupied(false);
};
Bar::Bar(int tableNumber) {
	setTableNumber(tableNumber);
	setCapacity(30);
	setDiners(0);
	setOccupied(false);
};
Bar::Bar(int tableNumber, int capacity) {
	setTableNumber(tableNumber);
	setCapacity(capacity);
	setDiners(0);
	setOccupied(false);
};
Bar::~Bar() {
};

void Bar::setTableNumber(int tableNumber) {
	_tableNumber = tableNumber;
};
int Bar::getTableNumber() {
	return _tableNumber;
};
int Bar::getCapacity() {
	return _capacity;
};

void Bar::setTimeSeated(std::string time) {
	_timeSeated = time;
};
std::string Bar::getTimeSeated() {
	return _timeSeated;
};
bool Bar::getOccupied() {
	return _occupied;
};

void Bar::setDiners(int number) {
	if (number > getCapacity()) {
		throw "The bar is too full to seat this many diners";
	}
	else if(number == getCapacity()) {
			setOccupied(true);
			_numberOfDiners = number;
		}
	else if( number < getCapacity()) {
		setOccupied(false);
		_numberOfDiners = number;
	}
	else {
		setOccupied(false);
		_numberOfDiners = number;
	}
};
int Bar::getDiners() {
	return _numberOfDiners;
};

std::string Bar::getSeatingType(){
    return "bar";
}

void Bar::removeDiners() {
	throw "Not implemented";
};

