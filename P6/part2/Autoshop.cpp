//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NBB
// Date:           11/06/2020
//==============================================
//  Autoshop.cpp
//  ws6
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
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
      out << "--------------------------------" << std::endl
          << "| Cars in the autoshop!        |"<< std::endl
          << "--------------------------------"<< std::endl;
       for (auto& i : m_vehicles) {
           i->display(out);
           out<< std::endl;
       }
       out << "--------------------------------"<< std::endl;
    }
    Autoshop::~Autoshop(){
       for (auto& i : m_vehicles) {
            delete i;
            i = nullptr;
        }
    };
}
