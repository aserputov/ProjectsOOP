//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NBB
// Date:           18/10/2020
//==============================================
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments

//  Reservation.cpp
//  laba4
//
//  Created by Anatoliy on 10/12/20.
//  Copyright © 2020 Anatoliy. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include "Reservation.h"

using namespace std;
namespace sdds{
    Reservation::Reservation(){
        res_name = "";
        res_id = "";
        res_email = "";
        res_num_ppl = 0;
        res_day = 1;
        res_hour = 1;
    }

    Reservation::Reservation(const string& res){
      string res_s = res;

      res_id = res_s.substr(0, res_s.find(':'));

      res_s.erase(0, res_s.find(':') + 1);
      res_name = res_s.substr(0, res_s.find(','));

      res_s.erase(0, res_s.find(',') + 1);
      res_email =res_s.substr(0, res_s.find(','));
        
      res_s.erase(0, res_s.find(',') + 1);
      res_num_ppl = stoi(res_s.substr(0, res_s.find(',')));

      res_s.erase(0, res_s.find(',') + 1);
      res_day = stoi(res_s.substr(0, res_s.find(',')));

      res_s.erase(0, res_s.find(',') + 1);
      res_hour = stoi(res_s.substr(0, res_s.find(',')));

      res_id.erase(res_id.find_last_not_of(' ') + 1);
      res_id.erase(0, res_id.find_first_not_of(' '));

      res_name.erase(res_name.find_last_not_of(' ') + 1);
      res_name.erase(0, res_name.find_first_not_of(' '));

      res_email.erase(res_email.find_last_not_of(' ') + 1);
      res_email.erase(0, res_email.find_first_not_of(' '));
        
      res_email = "<" + res_email + ">";
     
    }
    std::ostream& operator<<(ostream& os, const Reservation& rs){
        
        os << "Reservation " << rs.res_id << ": ";
        os << setw(10) << setfill(' ') << right << rs.res_name;
        os << "  " << setw(24) << setfill(' ') << left << rs.res_email;

        if(rs.res_hour >= 6 && rs.res_hour <= 9){
            os << "Breakfast";
        }else if(rs.res_hour >= 11 && rs.res_hour <= 15){
             os << "Lunch";
        }else if(rs.res_hour >= 17 && rs.res_hour <= 21){
             os << "Dinner";
        }else{
            os << "Drinks";
        }
        
       os << " on day " << rs.res_day << " @ " << rs.res_hour << ":00" << " for " << rs.res_num_ppl
            << " people." << endl;
        
        return os;
       };


}
