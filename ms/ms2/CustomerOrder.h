// Name: Anatoliy Serputov
// Seneca Student ID: 167389188
// Seneca email: aserputov@myseneca.com
// Date of completion: 20.11.20
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
//  CustomerOrder.h
//  ms2
//
//  Created by Anatoliy on 19.11.2020.
//

#ifndef CUSTOMERORDER_H
#define CUSTOMERORDER_H
#include <iostream>
#include <cstring>
#include "Station.h"
struct Item
{
    std::string m_itemName;
    unsigned int m_serialNumber = 0;
    bool m_isFilled = false;

    Item(const std::string& src) : m_itemName(src) {};
};

class CustomerOrder{
    private:
        std::string m_name;
        std::string m_product;
        unsigned int m_cntItem;
        Item** m_lstItem = {};
        static size_t m_widthField;
    public:
        CustomerOrder();
        CustomerOrder(std::string& str);
        CustomerOrder(CustomerOrder& other);
        CustomerOrder& operator=(CustomerOrder& other) = delete;
        CustomerOrder(CustomerOrder&& other) noexcept;
        CustomerOrder& operator=(CustomerOrder&& other) noexcept;
        ~CustomerOrder();
        bool isOrderFilled() const;
        bool isItemFilled(const std::string& itemName) const;
        void fillItem(Station& station, std::ostream& os);
        void display(std::ostream& os) const;
};





#endif /* CUSTOMERORDER_H */
