// Name: Serputov Anatoliy
// Seneca Student ID: 167389188
// Seneca email: aserputov@myseneca.ca
// Date of completion: 23/11/20
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
//  Workstation.cpp
//  ms3
//
//  Created by Анатолий on 23.11.2020.
//

#include "Workstation.h"

    Workstation::Workstation(const std::string& str) : Station(str){
        m_pNextStation = nullptr;
    }
    void Workstation::runProcess(std::ostream& os){
        if(!m_orders.empty()){
            if(!m_orders.front().isOrderFilled())
                m_orders.front().fillItem(*this, os);
        }
    }
    bool Workstation::moveOrder(){
        if (!m_orders.empty() && m_orders.front().isItemFilled(getItemName()) && m_pNextStation != nullptr){
            *m_pNextStation += std::move(m_orders.front());
                m_orders.pop_front();
            return true;
        }
        return false;
    }
    void Workstation::setNextStation(Station& station){
        m_pNextStation = (Workstation*) &station;
    }
    const Workstation* Workstation::getNextStation() const {
        return m_pNextStation;
    }
    bool Workstation::getIfCompleted(CustomerOrder& cust) {
        if (!m_orders.empty() && m_orders.front().isOrderFilled()) {
                cust = std::move(m_orders.front());
                m_orders.pop_front();
                return true;
        }
        return false;
    }
    void Workstation::display(std::ostream& os) {
        os << getItemName() << " --> ";
        if(m_pNextStation == nullptr){
            os << "END OF LINE";
        }else
            os << m_pNextStation->getItemName();;
        os << std::endl;
    }
    Workstation& Workstation::operator+=(CustomerOrder&& cust_ord) {
        m_orders.push_back(std::move(cust_ord));
        return *this;
    }
