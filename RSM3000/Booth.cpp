#include "Booth.h"

// Private
void Booth::setCapacity(int capacity) {
	_capacity = capacity;
};

void Booth::setOccupied(bool occupied) {
	_occupied = occupied;
};

// Public
Booth::Booth() {
	setTableNumber(201);
	setCapacity(6);
	setDiners(0);
	setOccupied(false);
};

Booth::Booth(int tableNumber) {
	setTableNumber(tableNumber);
	setCapacity(6);
	setDiners(0);
	setOccupied(false);
};

Booth::Booth(int tableNumber, int capacity) {
	setTableNumber(tableNumber);
	setCapacity(capacity);
	setDiners(0);
	setOccupied(false);
};

Booth::~Booth() {
};

void Booth::setTableNumber(int tableNumber) {
	_tableNumber = tableNumber;
};

int Booth::getTableNumber() {
	return _tableNumber;
};

void Booth::setTimeSeated(std::string time) {
	_timeSeated = time;
};

std::string Booth::getTimeSeated() {
	return _timeSeated;
};

void Booth::setDiners(int number) {
	_numberOfDiners = number;
	if (number == 0) {
		setOccupied(false);
	}
	else {
		setOccupied(true);
	}
};

int Booth::getDiners() {
	return _numberOfDiners;
};

int Booth::getCapacity() {
	return _capacity;
};

bool Booth::getOccupied() {
	return _occupied;
};

std::string Booth::getSeatingType(){
    return "booth";
}

void Booth::removeDiners() {
	setDiners(0);
	setOccupied(false);
};
