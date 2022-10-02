#include "Booth.h"
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

void Booth::setCapacity(int capacity) {
	_capacity = capacity;
};
int Booth::getCapacity() {
	return _capacity;
};

void Booth::setTimeSeated(std::string time) {
	_timeSeated = time;
};
std::string Booth::getTimeSeated() {
	return _timeSeated;
};

void Booth::setOccupied(bool occupied) {
	_occupied = occupied;
};
bool Booth::getOccupied() {
	return _occupied;
};

void Booth::setDiners(int number) {
	_numberOfDiners = number;
};
bool Booth::getDiners() {
	return _numberOfDiners;
};

std::string Booth::getSeatingType(){
    return "booth";
}
