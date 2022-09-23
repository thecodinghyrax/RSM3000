#include "Table.h"
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

void Table::setCapacity(int capacity) {
	_capacity = capacity;
};
int Table::getCapacity() {
	return _capacity;
};

void Table::setTimeSeated(std::string time) {
	_timeSeated = time;
};
std::string Table::getTimeSeated() {
	return _timeSeated;
};

void Table::setOccupied(bool occupied) {
	_occupied = occupied;
};
bool Table::getOccupied() {
	return _occupied;
};

void Table::setDiners(int number) {
	_numberOfDiners = number;
};
bool Table::getDiners() {
	return _numberOfDiners;
};
