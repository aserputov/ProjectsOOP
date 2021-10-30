//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NBB
// Date:           18/10/2020
//==============================================
//  Restaurant.cpp
//  laba4
//
//  Created by Anatoliy on 10/14/20.
//  Copyright © 2020 Anatoliy. All rights reserved.
//
#include <iostream>
#include "Restaurant.h"
using namespace std;
namespace sdds{
    Restaurant::Restaurant(){
        num_reservs = 0;
        arr_obj = nullptr;
    }
    Restaurant::Restaurant(Reservation* reservations[], size_t cnt){
        num_reservs = cnt;
        arr_obj = new Reservation[cnt];
        for (size_t i = 0; i < cnt; ++i) {
            arr_obj[i] = *reservations[i];
        }
    }
    Restaurant::Restaurant(const Restaurant &rs) {
           if (rs.arr_obj != nullptr) {
                num_reservs = rs.num_reservs;
                arr_obj = new Reservation[rs.size() + 1];
                    for (size_t i = 0; i < rs.size(); ++i) {
                        arr_obj[i] = rs.arr_obj[i];
                    }
           }
    }
    Restaurant::Restaurant(Restaurant &&rs) {
        if (rs.arr_obj != nullptr) {
             
              num_reservs = rs.num_reservs;
              arr_obj = rs.arr_obj;
              rs.num_reservs = 0;
              rs.arr_obj = nullptr;
        }
    }
    size_t Restaurant::size() const {
        return num_reservs;
    }
    std::ostream& operator<<(std::ostream& os, const Restaurant& rs){
       if(rs.size() == 0){
           os << "--------------------------" << endl;
           os << "Fancy Restaurant" << endl;
           os <<"--------------------------" << endl;
           os <<"The object is empty!" << endl;
           os << "--------------------------" << endl;
       }else if(rs.size() != 0){
           os << "--------------------------" << endl;
           os << "Fancy Restaurant" << endl;
           os << "--------------------------" << endl;
           for (size_t i = 0; i < rs.size(); ++i) {
               os << rs.arr_obj[i];
           }
           os << "--------------------------" << endl;
       }
           return os;
     }
    Restaurant::~Restaurant(){
        delete[] arr_obj;
        arr_obj = nullptr;
    }
}
