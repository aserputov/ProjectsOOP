//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NBB
// Date:           18/10/2020
//==============================================
//  ConfirmationSender.cpp
//  laba4
//
//  Created by Anatoliy on 10/17/20.
//  Copyright © 2020 Anatoliy. All rights reserved.
//
#include <ostream>
#include "ConfirmationSender.h"
using namespace std;
namespace sdds{
      ConfirmationSender::ConfirmationSender(){
           res_arr  = nullptr;
           res_numb = 0;
      }
      ConfirmationSender::ConfirmationSender(const ConfirmationSender &rs) {
          if (rs.res_arr != nullptr) {
              res_numb = rs.res_numb;
              res_arr = new const Reservation * [rs.res_numb+1];
              for (size_t i = 0; i < rs.res_numb; ++i) {
                  res_arr[i] = rs.res_arr[i];
              }
          }
      }
    ConfirmationSender &ConfirmationSender::operator+=( const Reservation &rs){
        bool check = false;
            if (res_numb == 0) {
                res_arr = new const Reservation* [res_numb + 1];
                res_arr[0] = &rs;
                res_numb++;
            }else {
                for (size_t i = 0; i < res_numb; i++) {
                        check = (&rs == res_arr[i]);
                }
                if (!check) {
                    const Reservation* tmp[sizeof(res_arr)];
                    for (size_t i = 0; i < res_numb; i++) {
                        tmp[i] = res_arr[i];
                    }
                    delete[] res_arr;
                    res_arr = new const Reservation* [res_numb + 1];
                    for (size_t i = 0; i < res_numb; i++) {
                        res_arr[i] = tmp[i];
                    }
                        res_arr[res_numb] = &rs;
                        res_numb++;
                      }
                  }
        return *this;
    }
    ConfirmationSender& ConfirmationSender::operator-=( const Reservation& rs){
         bool check = false;
         size_t i = 0;
         if (res_arr != nullptr) {
             do{
                check = (&rs == res_arr[i++]);
             }while (i < res_numb && !check);
         if (check) {
            res_arr[i - 1] = nullptr;
         }
      }
        return *this;
    }
    std::ostream& operator<<(std::ostream& os, const ConfirmationSender& confirm){
        if(confirm.res_numb == 0){
            os << "--------------------------" << endl;
            os << "Confirmations to Send"     << endl;
            os << "--------------------------" << endl;
            os << "The object is empty!"      << endl;
            os << "--------------------------" << endl;
        }else if(confirm.res_numb != 0){
            os << "--------------------------" << endl;
            os << "Confirmations to Send" << endl;
            os << "--------------------------" << endl;
             for (size_t i = 0; i < confirm.res_numb; i++) {
                if (confirm.res_arr[i] != nullptr) {
                        os << *confirm.res_arr[i];
                }
             }
            os << "--------------------------" << endl;
        }
            return os;
        }


    ConfirmationSender::ConfirmationSender(ConfirmationSender &&rs){
           if (rs.res_arr != nullptr) {
               
                res_arr = rs.res_arr;
                res_numb = rs.res_numb;
                rs.res_numb = 0;
                rs.res_arr = nullptr;
           }
       }
      ConfirmationSender::~ConfirmationSender(){
          delete[] res_arr;
          res_arr = nullptr;
      }
}



 
    
   

