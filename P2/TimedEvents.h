//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NBB
// Date:           27/09/2020
//==============================================
//  TimedEvents.h
//  Lab2
//
//  Created by Анатолий on 9/27/20.
//  Copyright © 2020 Anatoliy. All rights reserved.
//

#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H
#include <iostream>
#include <chrono>
#include <cstring>

namespace sdds{
const int MAX_NUMBER = 7;
class TimedEvents{
    private:
        size_t rec_stored;
        std::chrono::steady_clock::time_point start;
        std::chrono::steady_clock::time_point end;
     struct{
         std::string event_n;
         std::string  predef_time = "nanoseconds";
         std::chrono::steady_clock::duration duration;
    }a_rec[MAX_NUMBER];
    public:
        TimedEvents();
        void startClock();
        void stopClock();
        void recordEvent(const char* rec_time);
        friend std::ostream & operator << (std::ostream &out,  TimedEvents &T);
};
}


#endif /* SDDS_TIMEDEVENTS_H */
