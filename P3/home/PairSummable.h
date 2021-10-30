//
//  PairSummable.h
//  laba3
//
//  Created by Anatoliy on 10/8/20.
//  Copyright © 2020 Anatoliy. All rights reserved.
//
#pragma once
#ifndef PAIRSUMMABLE_H
#define PAIRSUMMABLE_H
#include <cstring>
#include <string>
#include "Pair.h"

namespace sdds{
template<typename K,typename V>

class PairSummable : public Pair<K,V> {
    private:
        static V initial;
        static size_t field_w ;
    public:

        PairSummable(){};
        PairSummable(const K& key, const V& value = initial):Pair<K, V>(key, value) {
            
            if (key.size() > field_w) {
                field_w = key.size();
            }
            
        };
    PairSummable& operator+=(const PairSummable& source){
       
        if (this->key() == source.key()) {
             PairSummable temp(source.key(),this->value() + source.value());
             *this = temp;
     }
        return *this;
    };
        void display(std::ostream& os) const {
            os.width(field_w);
            os << std::left;
            Pair<K, V>::display(os);
            os.width(0);
            os << std::right;
        };
    
};
template<>
std::string PairSummable<std::string, std::string>::initial = "";
template<>
int PairSummable<std::string,int>::initial = 0;
template<typename K, typename V>
size_t PairSummable<K, V>::field_w = 0u;
template<>
PairSummable<std::string,std::string>& PairSummable<std::string, std::string>::operator +=(const PairSummable& source) {
    if (this->key() == source.key()) {
        std::string temp;
        if(this->value() == "") {
            temp = source.value();
        }else {
             temp = this->value()+ ", " + source.value();
        }
        PairSummable tempObj(this->key(), temp);
        *this = tempObj;
    }
    return *this;
}
}

#endif /* PAIRSUMMABLE_H */
