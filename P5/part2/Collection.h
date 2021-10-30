//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NBB
// Date:           22/10/2020
//==============================================
//I receive small help(like an idea) for my operator += and T& [] from Aldiyar Nurgazin (121026199) and Some ideas and gave me direction in main.cpp
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
            for (size_t i = 0; i < i_size; i++) {
                if (items[i].title() == item.title()) {
                    return *this;
                }
            }
            T* i_tmp = new T[i_size + 1];
            for (size_t i = 0; i < i_size; i++) {
                i_tmp[i] = items[i];
            }
            i_tmp[i_size] = item;
            delete[] items;
            items = i_tmp;
            ++i_size;
            if (i_observer != nullptr) {
                i_observer(*this, item);
            }
            return *this;
        };
        T& operator[](size_t idx) const {
            if (idx >= i_size) {
                std::string str = "Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(i_size) + "] items.";
                throw std::out_of_range(str);
            }
            return items[idx];
        };
        T* operator[](std::string title) const {
            bool check = false;
            size_t i = 0;
                do{
                    if (items[i].title() == title) {
                        check = true;
                        return &items[i];
                    }else
                        i++;
                }while(!check && i < i_size);
            
            return nullptr;
        };
        ~Collection(){
             delete[] items;
             items = nullptr;
         };
         friend std::ostream& operator<< (std::ostream& os, const Collection& cl) {
             for (size_t i = 0; i < cl.i_size; i++) {
                os << cl[i];
            }
            return os;
         };
    };



}
#endif /* SDDS_COLLECTION_H */
