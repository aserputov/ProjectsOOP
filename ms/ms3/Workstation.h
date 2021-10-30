// Name: Serputov Anatoliy
// Seneca Student ID: 167389188
// Seneca email: aserputov@myseneca.ca
// Date of completion: 23/11/20
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
//  Workstation.h
//  ms3
//
//  Created by Анатолий on 23.11.2020.
//

#ifndef WORKSTATION_H
#define WORKSTATION_H
#include <deque>
#include "CustomerOrder.h"

class Workstation:public Station{
    private:
        std::deque<CustomerOrder> m_orders;
        Workstation* m_pNextStation;
    public:
        Workstation(const std::string& str);
    
        Workstation(const Workstation& other) = delete;
        Workstation& operator=(const Workstation& other) = delete;
        Workstation(const Workstation&& other) = delete;
        Workstation& operator=(const Workstation&& other) = delete;
    
        void runProcess(std::ostream& os);
        bool moveOrder();
        void setNextStation(Station& station);
        const Workstation* getNextStation() const;
        bool getIfCompleted(CustomerOrder& order);
        void display(std::ostream& os);
        Workstation& operator+=(CustomerOrder&&);
};

#endif /* WORKSTATION_H */
