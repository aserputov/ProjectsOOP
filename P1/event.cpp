//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NBB
// Date:           22/09/2020
//==============================================
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//  event.cpp
//
//
//  Created by Anatoliy on 9/22/20.
//  Copyright © 2020 Anatoliy. All rights reserved.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include "event.h"
#include "event.h"

using namespace std;
unsigned int g_sysClock = 0;
namespace sdds{
   
    Event::Event(){
        d_event = nullptr;
        p_time = 0;
    }
    Event::Event(const Event& src ){
        d_event = nullptr;
        *this = src;
    }
    void Event::display() const {
        static int count = 1 ;
            if(d_event == nullptr){
                cout << std::setw(3) << std::setfill(' ')<< count << ". [ No Event ]"<< endl;
            }else{
                cout << std::setw(3) << std::setfill(' ')<< count << ". " <<
                std::setw(2)<<std::setfill('0') << (p_time/3600) << ":" <<
                std::setw(2)<<std::setfill('0') << (p_time/60)-((p_time/3600)*60) <<":"<<
                std::setw(2)<<std::setfill('0') << (p_time%60) <<" -> "<< d_event << endl;
        }
        count++;
    };
    void Event::setDescription(char *description){
        if(description != nullptr){
            p_time = g_sysClock;
            delete[] d_event;
            d_event = new char[strlen(description)+1];
            strcpy(d_event,description);
        }else{
            delete[] d_event;
            d_event = nullptr;
        }
        
    }
    Event& Event::operator=(const Event& src) {
        if (this != &src) {  // check for self-assignment
            p_time = src.p_time;
        // deallocate previously allocated dynamic memory
            if(d_event!= nullptr){
                delete[]d_event;
            }
        // allocate new dynamic memory
            if (src.d_event != nullptr) {
                d_event = new char[strlen(src.d_event)+1];
                strcpy(d_event, src.d_event);
                // copy resource data
                for (unsigned int i= 0; i < strlen(src.d_event); i++){
                    d_event[i] = src.d_event[i];
                }
            }
        }
    return *this;
    }

    Event::~Event(){
    delete[] d_event;
    d_event = nullptr;
    }

}
