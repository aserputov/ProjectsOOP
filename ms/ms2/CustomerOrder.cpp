// Name: Anatoliy Serputov
// Seneca Student ID: 167389188
// Seneca email: aserputov@myseneca.com
// Date of completion: 20.11.20
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
// I received a small help as an iadea how can do
// my constructor with vector from my classmate
//  CustomerOrder.cpp
//  ms2
//
//  Created by Anatoliy on 19.11.2020.
//
#include <vector>
#include <iomanip>
#include "CustomerOrder.h"
#include "Utilities.h"

size_t CustomerOrder::m_widthField = 0;

    CustomerOrder::CustomerOrder(){
        m_name = "";
        m_product = "";
        m_cntItem = 0;
        m_lstItem = nullptr;
    };
    CustomerOrder::CustomerOrder(std::string& str){
       Utilities utl;
       size_t next_pos = 0;
       bool more;
       m_cntItem = 0;
       m_name = utl.extractToken(str, next_pos, more);
       m_product = utl.extractToken(str, next_pos, more);
       std::vector<std::string> vct;
       while(next_pos){
           vct.push_back(utl.extractToken(str, next_pos, more));
           m_cntItem++;
       }
       m_lstItem = new Item*[m_cntItem];
       for (size_t i = 0; i < m_cntItem; ++i) {
           m_lstItem[i] = new Item(vct[i]);
       }
       if (m_widthField < utl.getFieldWidth())
           m_widthField = utl.getFieldWidth();
    };
    CustomerOrder::CustomerOrder(CustomerOrder& other){
        throw "Not allowed to copy";
    };
//   CustomerOrder& CustomerOrder::operator=(const CustomerOrder& other) = delete;
    CustomerOrder::CustomerOrder(CustomerOrder&& other) noexcept{
        *this = std::move(other);
    };
    CustomerOrder& CustomerOrder::operator=(CustomerOrder&& other) noexcept{
        if(this != &other){
            if(m_lstItem){
                for (size_t i = 0; i < m_cntItem; ++i)
                    delete m_lstItem[i];
                delete[] m_lstItem;
            }
        m_name = other.m_name;
        m_product = other.m_product;
        m_cntItem = other.m_cntItem;
        m_lstItem = other.m_lstItem;

        other.m_name = "";
        other.m_product = "";
        other.m_cntItem = 0;
        other.m_lstItem = nullptr;
        
        }
        return *this;
    };
    CustomerOrder::~CustomerOrder(){
        for(unsigned int i = 0; i < m_cntItem; i++){
            delete m_lstItem[i];
            m_lstItem[i] = nullptr;
        }
        delete[] m_lstItem;
        m_lstItem = nullptr;
    };
    bool CustomerOrder::isOrderFilled() const{
        for(unsigned int i = 0; i < m_cntItem; i++) {
            if(m_lstItem[i]->m_isFilled == false)
                return false;
        }
        return true;
    };
    bool CustomerOrder::isItemFilled(const std::string& itemName) const{
        for(unsigned int i = 0; i < m_cntItem; i++){
            if(m_lstItem[i]->m_itemName == itemName)
                return m_lstItem[i]->m_isFilled;
        }
        return true;
    };
    void CustomerOrder::fillItem(Station& station, std::ostream& os){
        for(unsigned int i = 0; i < m_cntItem; i++){
            if(station.getItemName() == m_lstItem[i]->m_itemName){
                if(station.getQuantity() < 0){
                    os << "    Unable to fill ";
                }else{
                    m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
                    m_lstItem[i]->m_isFilled = true;
                    station.updateQuantity();
                    os << "    Filled ";
                }
                os << m_name << ", " << m_product << " [" << station.getItemName() << "]" <<  std::endl;
            }
        }
    };
    void CustomerOrder::display(std::ostream& os) const{
        os << m_name << " - " << m_product << std::endl;
        for (unsigned int i = 0; i < m_cntItem; i++){
            os << "[" ;
            os << std::setfill('0') << std::setw(6) << m_lstItem[i]->m_serialNumber;
            os << "] ";
            os << std::setw(m_widthField) << std::setfill(' ') << m_lstItem[i]->m_itemName << " - ";
            if(!m_lstItem[i]->m_isFilled){
                os << "MISSING";
            }else{
                os << "FILLED";
            }
            os << std::endl;
        }
    
    };
