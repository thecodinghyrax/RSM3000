#include "Bar.h"
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

void Bar::setCapacity(int capacity) {
	_capacity = capacity;
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

void Bar::setOccupied(bool occupied) {
	_occupied = occupied;
};
bool Bar::getOccupied() {
	return _occupied;
};

void Bar::setDiners(int number) {
	_numberOfDiners = number;
};
bool Bar::getDiners() {
	return _numberOfDiners;
};

std::string Bar::getSeatingType(){
    return "bar";
}

