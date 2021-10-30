//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NBB
// Date:           11/06/2020
//==============================================
//  Autoshop.hpp
//  ws6
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//  Created by Анатолий on 10/29/20.
//  Copyright © 2020 Anatoliy. All rights reserved.
//

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include <iostream>
#include <vector>
#include <list>
#include "Vehicle.h"

namespace sdds{
class Autoshop{
        private:
            std::vector<Vehicle*> m_vehicles;
        public:
            Autoshop& operator +=(Vehicle* theVehicle);
            void display(std::ostream& out) const;
            ~Autoshop();
            template <class T>
            void select(T test, std::list<const Vehicle*>& vehicles) {
               for (auto& i: m_vehicles) {
                   if (test(i)) vehicles.push_back(i);
               }
            }
    };
}

#endif /* SDDS_AUTOSHOP_H */
