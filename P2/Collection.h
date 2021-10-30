//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NBB
// Date:           22/10/2020
//==============================================
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
//  Collection.h
//  laba5
//
//  Created by Анатолий on 10/22/20.
//  Copyright © 2020 Anatoliy. All rights reserved.
//

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <iostream>
namespace sdds{
template<class T>
    class Collection {
       private:
           std::string collection_name;
           T *items;
           size_t i_size;
           void (*i_observer) (const Collection<T>&, const T&) = nullptr;
    public:
        Collection(std::string name){
            collection_name = name;
            items = nullptr;
            i_size = 0;
            i_observer = nullptr;
        };
        
        Collection(const Collection&) = delete;
        Collection& operator=(const Collection& src) = delete;
        Collection(Collection&& src) = delete;
        Collection& operator=(Collection&& src) = delete;
        
        const std::string& name() const{
            return collection_name;
        };
        size_t size() const{
            return i_size;
        };
        void setObserver(void (*observer)(const Collection<T>&, const T&)){
            i_observer = observer;
        };
        Collection<T>& operator+=(const T& item) {
            bool check = false;
            for (size_t i = 0; i < i_size; i++) {
                if (items[i].title() == item.title())
                    check = true;
            }
            if (check) {
                return *this;
            }
            T* tmp = items;

            items = new T[i_size + 1];
            for (size_t i = 0; i < i_size; i++) {
                items[i] = tmp[i];
            }

            items[i_size] = item;

            i_size++;

            if (i_observer != nullptr) {
                i_observer(*this, item);
            }
            delete[] tmp;
            return *this;
            
//            for (size_t i = 0; i < m_size; i++) {
//                if (m_items[i].title() == item.title()) {
//                    return *this;
//                }
//            }
//            T* temp = new T[m_size + 1];
//            for (size_t i = 0; i < m_size; i++) {
//                temp[i] = m_items[i];
//            }
//            temp[m_size] = item;
//            delete[] m_items;
//            m_items = temp;
//            ++m_size;
//
//            if (addItem != nullptr) {
//                addItem(*this, m_items[m_size - 1]);
//            }
//            return *this;
        };
        T& operator[](size_t idx) const {
            if (idx >= i_size) {
                //throw "Bad index"+std::to_string(idx)+".Collection has"+ std::to_string(m_elements)+" items.";
                std::string s = "Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(i_size) + "] items.";
                throw std::out_of_range(s);
                //throw "bad index";
            }

            return items[idx];
        };
        T* operator[](std::string title) const {
            for (size_t i = 0; i < i_size; i++) {
                if (items[i].title() == title) {
                    return &items[i];
                }
            }
            return nullptr;
        };
        friend std::ostream& operator<< (std::ostream& os, const Collection& collection) {
            for (size_t i = 0; i < collection.size(); i++) {
                os << collection[i];
            }
            return os;
        };
        ~Collection(){
             delete[] items;
         };
    };



}
#endif /* SDDS_COLLECTION_H */
