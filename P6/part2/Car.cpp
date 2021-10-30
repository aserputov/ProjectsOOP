//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NBB
// Date:           11/06/2020
//==============================================
//  Car.cpp
//  ws6
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

//  Created by Анатолий on 10/29/20.
//  Copyright © 2020 Anatoliy. All rights reserved.
//


#include <iostream>
#include <iomanip>
#include <cstring>
#include "Car.h"

namespace sdds {
    Car::Car(std::istream& is) {
        std::string str;
        
        getline(is, car_maker, ','); 
        size_t t = car_maker.find_first_not_of(' ');
        car_maker = car_maker.substr(t, car_maker.find_last_not_of(' ') - t + 1);
        
        getline(is, str, ',');
        size_t i = 0 ;
        if(i < str.length() && str[i] == ' '){
            i++;
        }
        str = str.substr(i);
        if (str == "" || str == "n")
            car_cond = "new";
        else if (str == "b")
            car_cond = "broken";
        else if (str == "u")
            car_cond = "used";
        else
            throw "Invalid record!";
        
        std::getline(is, str, ',');
        try {
            max_speed = std::stod(str.substr(str.find(',', 0) + 1, str.find(',', str.find(',', 0) + 1) - str.find(',', 0) - 1));
        }catch (...) {
            throw "Invalid Record!";
        }
    }
    std::string Car::condition() const {
        return car_cond;
    }
    double Car::topSpeed() const {
        return max_speed;
    }
    void Car::display(std::ostream& out) const {
       out << "| " << std::setw(10) << std::right << car_maker
           << " | " << std::setw(6) << std::left << car_cond
           << " | " << std::setw(6) << std::fixed << std::setprecision(2) << topSpeed()
           << " |";
    }
}
