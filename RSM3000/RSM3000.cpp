#include <iostream>
#include <vector>
#include "SeatingGroup.h"
#include "Table.h"
#include "Booth.h"
#include "Bar.h"


int main()
{
    // Using a vector of smart pointers of the base class type
    // to store instances of derived classes. This allows us to 
    // keep all table types together in one place. 
    std::vector<std::unique_ptr<SeatingGroup>> restaurant;


    restaurant.emplace_back(new Table);
    restaurant.emplace_back(new Table(102));
    restaurant.emplace_back(new Table(103, 12));
    restaurant.emplace_back(new Booth);
    restaurant.emplace_back(new Booth(202));
    restaurant.emplace_back(new Booth(203, 4));
    restaurant.emplace_back(new Bar);
    restaurant.emplace_back(new Bar(302));
    restaurant.emplace_back(new Bar(303, 50));

    for (int i = 0; i < restaurant.size(); ++i) {
        std::cout << "Capacity: "<<restaurant.at(i)->getCapacity() << std::endl;
        std::cout << "Number of Diners: "<<restaurant.at(i)->getDiners() << std::endl;
        std::cout << "Is Occupied?: "<<restaurant.at(i)->getOccupied() << std::endl;
        std::cout << "Table Number: "<<restaurant.at(i)->getTableNumber() << std::endl;
        std::cout << "Time Seated: "<<restaurant.at(i)->getTimeSeated() << std::endl << std::endl;

    }
 


}
