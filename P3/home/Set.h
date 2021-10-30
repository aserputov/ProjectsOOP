//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NBB
// Date:           04/10/2020
//==============================================//
// Set.h
//  Lab3
//
//  Created by Anatoliy on 10/02/20.
//  Copyright © 2020 Anatoliy. All rights reserved.
//
#pragma once
#ifndef SET_H
#define SET_H
#include <cstring>

namespace sdds{
template<typename T ,unsigned int N>
    class Set{
        private:
            T set[N];
            size_t cur_st;
        public:
            Set(){
                cur_st=0;
            };
            size_t size() const{
                return cur_st;
            };
            const T& operator[](size_t idx) const{
                if(idx < cur_st){
                     return set[idx];
                }else{
                    return set[0];
                }
            };
            void operator+=(const T& item){
                if(cur_st < N){
                    set[cur_st] = item;
                    cur_st++;
                }

            };
        
    };
}
#endif /* SET_h */
