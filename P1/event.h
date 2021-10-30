//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NBB
// Date:           22/09/2020
//==============================================
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//  event.h
//
//
//  Created by Anatoliy on 9/21/20.
//  Copyright © 2020 Anatoliy. All rights reserved.
//

#ifndef event_h
#define event_h
#include <string>
#include <string.h>
using namespace std;
extern unsigned int g_sysClock;
namespace sdds{

class Event{
    
    char *d_event ;
    unsigned int p_time ;
    
    public:
    Event();
    Event(const Event& src);
    Event& operator=(const Event& src) ;
    void display() const;
    void setDescription( char *description);
    ~Event();
    };
}





#endif /* event_h */
