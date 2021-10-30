//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NBB
// Date:           11/06/2020
//==============================================
//  Racecar.hpp
//  ws6
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//  Created by Анатолий on 10/29/20.
//  Copyright © 2020 Anatoliy. All rights reserved.
//

#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H
#include <iostream>
#include "Car.h"

namespace sdds{
    class Racecar:public Car{
    private:
        double m_booster;
    public:
        Racecar(std::istream& in);
        void display(std::ostream& out) const;
        double topSpeed() const;
    };
}

#endif /* SDDS_RACECAR_H */
