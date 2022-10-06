#include "WaitingArea.h"

WaitingArea::WaitingArea() {
  setPartyNumber(0);
  setDinerName("");
};
WaitingArea::WaitingArea(std::string name, int num) {
  setPartyNumber(num);
  setDinerName(name);
};
WaitingArea::~WaitingArea() { };

void WaitingArea::setTableNumber(int tableNumber) {
    _tableNumber = tableNumber;
};
int WaitingArea::getTableNumber() {
    return _tableNumber;
};

void WaitingArea::setCapacity(int capacity) {
    _capacity = capacity;
};
int WaitingArea::getCapacity() {
    return _capacity;
};

void WaitingArea::setTimeSeated(std::string time) {
    _timeSeated = time;
};
std::string WaitingArea::getTimeSeated() {
    return _timeSeated;
};

void WaitingArea::setOccupied(bool occupied) {
    _occupied = occupied;
};
bool WaitingArea::getOccupied() {
    return _occupied;
};

std::string WaitingArea::getSeatingType(){
    return "waiting area";
}

void WaitingArea::setDiners(int number) {
  _numberOfDiners = number;
}
bool WaitingArea::getDiners() {
  return _numberOfDiners;
}

void WaitingArea::setPartyNumber(int num) {
    partyNumber = num;
}

int WaitingArea::getPartyNumber() {
    return partyNumber;
}

void WaitingArea::setDinerName(std::string name) {
  dinerName = name;
}
std::string WaitingArea::getDinerName() {
  return dinerName;
}

bool WaitingArea::isNumber(std::string str) {
    for (char const &n : str) {
        if (std::isdigit(n) == 0) {
            return false;
        }
    }
    return true;
}

std::string WaitingArea::promptForName() {
    std::string nameInput = "";

    std::cout << "Please enter the name of a diner: " << std::endl;
    std::cin.ignore();
    std::getline(std::cin, nameInput);

    while (isNumber(nameInput)) {
        std::cout << "Invalid Input - Entry cannot be a number" << std::endl;
        std::cout << "Please enter the name of a diner: " << std::endl;
        std::cin >> nameInput;
    }

    return nameInput;
}
