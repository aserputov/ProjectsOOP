//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NBB
// Date:           11/06/2020
//==============================================
//  Racecar.cpp
//  ws6
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//  Created by Анатолий on 10/29/20.
//  Copyright © 2020 Anatoliy. All rights reserved.
//

#include <iostream>
#include <cstring>
#include "Racecar.h"

namespace sdds {
    Racecar::Racecar(std::istream& in) :Car(in) {
        std::string str;
        getline(in, str);
        if (str != "") {
            m_booster = stod(str);
        }
    }
    void Racecar::display(std::ostream& out) const {
        Car::display(out);
        out << "*";
    }
    double Racecar::topSpeed() const {
        return Car::topSpeed() * (1 + m_booster);
    }


}
