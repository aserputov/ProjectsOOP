// Name: Serputov Anatoliy
// Seneca Student ID: 167389188
// Seneca email: aserputov@myseneca.ca
// Date of completion: 11/11/20
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
// I found small idea for my constructor on google,
// but it was just an idea
//  Station.cpp
//  ms1
//
//  Created by Анатолий on 11/9/20.
//  Copyright © 2020 Anatoliy. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Station.h"
#include "Utilities.h"

    size_t Station::m_widthField = 0;
    int Station::id_generator = 0;

    Station::Station(){
        id = 0;
        name = "";
        description = "";
        serialNumber = 0;
        items_left = 0;
    }
    Station::Station(const std::string& str){
        Utilities utl;
        id = ++Station::id_generator;
        size_t next_pos = 0;
        bool check = false;
        if (str != "") {
            name = utl.extractToken(str, next_pos, check);
            if (check) {
                serialNumber = stoi(utl.extractToken(str, next_pos, check));
            }
            if (check) {
                items_left = stoi(utl.extractToken(str, next_pos, check));
            }
            if (m_widthField < utl.getFieldWidth()) {
                m_widthField = utl.getFieldWidth();
            }
            if (check) {
                description = utl.extractToken(str, next_pos, check);
            }
        }
    }
    const std::string& Station::getItemName() const{
        return name;
    }
    unsigned int Station::getNextSerialNumber(){
        return serialNumber++;
    }
    unsigned int Station::getQuantity() const{
        return items_left;
    }
    void Station::updateQuantity(){
        if (getQuantity()> 0){
            items_left--;
        }
    }
    void Station::display(std::ostream& os, bool full) const{
        os << "[" << std::setw(3) << std::setfill('0') << std::right << id<< "] ";
        os << "Item: " << std::setw(m_widthField) << std::setfill(' ') << std::left << name;
        os << " [" << std::setw(6) << std::setfill('0') << std::right << serialNumber << "]" << std::setfill(' ') << std::left;
        if (full != false) {
            os << " Quantity: " << std::setw(m_widthField) << items_left;
            os << " Description: " << description;
        }
            os << std::endl;
    }
    Station::~Station(){}
