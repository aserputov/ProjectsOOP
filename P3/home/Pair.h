//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NBB
// Date:           04/10/2020
//==============================================//
//  Pair.h
//  laba3
//
//  Created by Анатолий on 10/7/20.
//  Copyright © 2020 Anatoliy. All rights reserved.
//
#pragma once
#ifndef PAIR_H
#define PAIR_H
#include <iostream>

namespace sdds{
template<typename K,typename V>
    class Pair{
    private:
         K key_p;
         V value_p;
    public:
        Pair(){};
        Pair(const K& key, const V& value){
            key_p = key;
            value_p = value;
        };
        const K& key() const{
            return key_p;
        };
        const V& value() const{
            return value_p;
        };
       virtual void display(std::ostream& os) const{
            os << key_p << " : " << value_p << std::endl;
        };
    };
template<typename K,typename V>
    std::ostream& operator<<(std::ostream& os, const Pair<K, V>& pair){
        pair.display(os);
        return os;
    };
}

#endif /* PAIR_H */
