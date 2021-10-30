//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NBB
// Date:           11/06/2020
//==============================================
//  Car.h
//  ws6
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//  Created by Анатолий on 10/29/20.
//  Copyright © 2020 Anatoliy. All rights reserved.
//

#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include <iostream>
#include "Vehicle.h"

namespace sdds {
    class Car : public Vehicle {
    private:
        std::string car_maker;
        std::string car_cond;
        double max_speed;
    public:
        Car();
        Car(std::istream&);
        std::string condition() const;
        double topSpeed() const;
        void display(std::ostream& out) const;
    };

}

#endif
