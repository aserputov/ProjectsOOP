//
//  Autoshop.cpp
//  ws6
//
//  Created by Анатолий on 10/29/20.
//  Copyright © 2020 Anatoliy. All rights reserved.
//


#include <iostream>
#include <iomanip>
#include "Autoshop.h"

namespace sdds{
    Autoshop& Autoshop::operator +=(Vehicle* theVehicle){
        m_vehicles.push_back(theVehicle);
        return *this;
    }
    void Autoshop::display(std::ostream& out) const{
       auto ptr = m_vehicles.begin();
        out << "--------------------------------" << std::endl;
        out << "| Cars in the autoshop!        |" << std::endl;
        out << "--------------------------------" << std::endl;
        for (ptr = m_vehicles.begin(); ptr < m_vehicles.end(); ptr++)
            (*ptr)->display(out);
        out << "--------------------------------" << std::endl;
    }
    Autoshop::~Autoshop(){
        auto ptr = m_vehicles.begin();
        for (ptr = m_vehicles.begin(); ptr < m_vehicles.end(); ptr++)
            delete* ptr;
        }
}
