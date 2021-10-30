// Name: Serputov Anatoliy
// Seneca Student ID: 167389188
// Seneca email: aserputov@myseneca.ca
// Date of completion: 23/11/20
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
//  LineManager.h
//  ms3
//
//  Created by Анатолий on 26.11.2020.
//

#ifndef LINEMANAGER_H
#define LINEMANAGER_H
#include <vector>
#include "Workstation.h"

class LineManager{
    private:
        std::vector<Workstation*> AssemblyLine;
        std::deque<CustomerOrder> ToBeFilled;
        std::deque<CustomerOrder> Completed;
        unsigned int m_cntCustomerOrder;
        std::vector<Workstation*> add;
    public:
        LineManager(const std::string& str, std::vector<Workstation*>& obj_add, std::vector<CustomerOrder>& cust_ord);
        bool run(std::ostream& os);
        void displayCompletedOrders(std::ostream& os) const;
        void displayStations() const;
        void displayStationsSorted() const;
};

#endif /* LINEMANAGER_H */

