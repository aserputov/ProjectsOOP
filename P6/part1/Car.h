//
//  Car.hpp
//  ws6
//
//  Created by Анатолий on 10/29/20.
//  Copyright © 2020 Anatoliy. All rights reserved.
//

#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include<iostream>
#include "Vehicle.h"

namespace sdds{
class Car:public Vehicle {
        private:
            std::string maker;
            std::string auto_condition;
            double max_speed;
        public:
            Car(std::istream& details);
            std::string condition() const;
            double topSpeed() const;
            void display(std::ostream& out) const;
    };
}
#endif /* SDDS_CAR_H */
