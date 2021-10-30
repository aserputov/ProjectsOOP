//
//  PairSummable.h
//  laba3
//
//  Created by Анатолий on 10/8/20.
//  Copyright © 2020 Anatoliy. All rights reserved.
//
#pragma once
#ifndef PAIRSUMMABLE_H
#define PAIRSUMMABLE_H
#include <cstring>
#include "Pair.h"

namespace sdds{
template<typename K,typename V>
class PairSummable : public Pair<K,V> {
    private:
        static V initial;
    static size_t field_w ;
    public:

        PairSummable(){
            field_w = {0u};;
        };
        PairSummable(const K& key, const V& value = initial):Pair<K, V>(key, value) {
            
            if (key.size() > field_w) {
                field_w = key.size();
            }
            
        };
    PairSummable& operator+=(const PairSummable& source){
        if(this->Pair<K, V>::key() == source.key()){
//            && this* != source
            this->Pair<K, V>::value() + "," + source.value();
        }
        return Pair<K, V>::value();
    };
        void display(std::ostream& os) const {
            os.width(field_w);
            os << std::left;
            Pair<K, V>::display(os);
            os.width(0);
            os << std::right;
            void display();
        };

    
    
    PairSummable(const PairSummable& source) {
               
               *this = source; // calls assignment operator
           }
//    PairSummable& PairSummable::operator=(const PairSummable& source) {
//        if (this != &source) {  // check for self-assignment
//            no = source.no;
//            ng = source.ng;
//            // deallocate previously allocated dynamic memory
//            delete [] grade;
//            // allocate new dynamic memory
//            if (source.grade != nullptr) {
//                grade = new float[ng];
//                // copy resource data
//                for (int = 0; i < ng; i++)
//                    grade[i] = source.grade[i];
//            }
//            else {
//                grade = nullptr;
//            }
//        }
//        return *this;
//    }
    
};
template<>
std::string PairSummable<std::string, std::string>::initial = "";
template<>
int PairSummable<std::string,int>::initial = 0;

}

#endif /* PAIRSUMMABLE_H */
