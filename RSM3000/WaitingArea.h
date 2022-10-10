#ifndef WAITINGAREA_H
#define WAITINGAREA_H
#include "SeatingGroup.h"

class WaitingArea : public SeatingGroup {
protected:
  std::string dinerName;
  int partyNumber;

public:
  WaitingArea();
  WaitingArea(std::string name, int num);
  ~WaitingArea();

  void setTableNumber(int tableNumber);
  int getTableNumber();

  void setCapacity(int capacity);
  int getCapacity();

  void setTimeSeated(std::string time);
  std::string getTimeSeated();

  void setOccupied(bool occupied);
  bool getOccupied();

  std::string getSeatingType();

  void setDiners(int number);
  int getDiners();

  void setDinerName(std::string name);
  std::string getDinerName();

  void setPartyNumber(int num);
  int getPartyNumber();

  static std::string promptForName();
  static bool isNumber(std::string str);

  void removeDiners();

};

#endif // WAITINGAREA_H
