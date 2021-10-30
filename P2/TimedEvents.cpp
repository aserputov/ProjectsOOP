//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NBB
// Date:           27/09/2020
//==============================================//
//
//  TimedEvents.cpp
//  Lab2
//
//  Created by Анатолий on 9/27/20.
//  Copyright © 2020 Anatoliy. All rights reserved.
//

#include "TimedEvents.h"
#include "TimedEvents.h"
#include <iostream>
#include <chrono>
#include <iomanip>
#include <cstring>

using namespace std;
namespace sdds{

    TimedEvents::TimedEvents(): start{}, end{}{
        rec_stored = 0;
    }
    void TimedEvents::startClock(){
        start = std::chrono::steady_clock::now();
    }
    void TimedEvents::stopClock(){
        end = std::chrono::steady_clock::now();;
    }
    void TimedEvents::recordEvent(const char* rec_time){
        auto st = start;
        auto ed = end;
            if (rec_stored < MAX_NUMBER){
                a_rec[rec_stored].event_n = rec_time;
                a_rec[rec_stored].duration = ed - st;
                rec_stored++;
            }
    }
    std::ostream & operator << (std::ostream &out,TimedEvents &T){
          out << "--------------------------" << std::endl;
          out << "Execution Times:"<< std::endl;
          out << "--------------------------"<< std::endl;
            for (size_t i = 0; i < T.rec_stored; ++i){
             out << std::setw(20) << T.a_rec[i].event_n
                 << std::setw(12) << T.a_rec[i].duration.count()
                 << " " << T.a_rec[i].predef_time << std::endl;
            }
          out << "--------------------------" << std::endl;
        return out;
    }
    }
   

   
