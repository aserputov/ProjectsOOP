//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NBB
// Date:           11/06/2020
//==============================================
//  Utilities.cpp
//  ws6
//
// I received some small help and ideas from my classmates with logic of creatInstance function.
//  Created by Анатолий on 10/29/20.
//  Copyright © 2020 Anatoliy. All rights reserved.
//
#include <iostream>
#include <cstring>
#include <sstream>
#include "Utilities.h"

namespace sdds {
    Vehicle* createInstance(std::istream& in){
        char fr = '\0';
        char sc = '\0';
        std::string str = "";
        
        getline(in, str);
        std::stringstream strs(str);
        strs >> fr >> sc;
        
        if (strs) {
            switch (fr){
            case 'c':
            case 'C':
                return new Car(strs);
                break;
            case 'r':
            case 'R':
                return new Racecar(strs);
                break;
            default:
                throw fr;
                break;
            }
        }
            return nullptr;
    }
}
