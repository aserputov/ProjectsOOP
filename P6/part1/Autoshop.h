//
//  Autoshop.hpp
//  ws6
//
//  Created by Анатолий on 10/29/20.
//  Copyright © 2020 Anatoliy. All rights reserved.
//

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include <iostream>
#include <vector>
#include <functional>
#include "Vehicle.h"
namespace sdds{

class Autoshop{
        private:
            std::vector<Vehicle*> m_vehicles;
        public:
            Autoshop& operator +=(Vehicle* theVehicle);
            void display(std::ostream& out) const;
            ~Autoshop();
    };
}

#endif /* SDDS_AUTOSHOP_H */
