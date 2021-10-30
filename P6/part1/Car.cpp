//
//  Car.cpp
//  ws6
//
//  Created by Анатолий on 10/29/20.
//  Copyright © 2020 Anatoliy. All rights reserved.
//
#include <iostream>
#include <iomanip>
#include "Car.h"

namespace sdds{
void trim(std::string& str) {
    size_t t = str.find_first_not_of(' ');
    str = str.substr(t, str.find_last_not_of(' ') - t + 1);
}
    Car::Car(std::istream& details){
       std::string record;
       char buffer[4096];

       details.getline(buffer, sizeof(buffer));
       record.append(buffer, sizeof(buffer));
       record.append(buffer, details.gcount());


       size_t beginIndex = 0;
       size_t endIndex = 0;
   
       endIndex = record.find(",", beginIndex);
       std::string tag = record.substr(beginIndex, endIndex);

       size_t start = tag.find_first_not_of(' ');
       tag = (start == std::string::npos) ? "" : tag.substr(start);

       size_t end = tag.find_last_not_of(' ');
       tag = (end == std::string::npos) ? "" : tag.substr(0, end + 1);
        
       if (tag != "C" && tag != "c") {
           maker = "";
           auto_condition = "";
           auto_condition = 0.00;
           return;
       }
//        string res_s = res;
//
//         res_id = res_s.substr(0, res_s.find(':'));
//
//         res_s.erase(0, res_s.find(':') + 1);
//         res_name = res_s.substr(0, res_s.find(','));
//
//         res_s.erase(0, res_s.find(',') + 1);
//         res_email =res_s.substr(0, res_s.find(','));
//
//         res_s.erase(0, res_s.find(',') + 1);
//         res_num_ppl = stoi(res_s.substr(0, res_s.find(',')));
//
//         res_s.erase(0, res_s.find(',') + 1);
//         res_day = stoi(res_s.substr(0, res_s.find(',')));
//
//         res_s.erase(0, res_s.find(',') + 1);
//         res_hour = stoi(res_s.substr(0, res_s.find(',')));
//
//         res_id.erase(res_id.find_last_not_of(' ') + 1);
//         res_id.erase(0, res_id.find_first_not_of(' '));
//
//         res_name.erase(res_name.find_last_not_of(' ') + 1);
//         res_name.erase(0, res_name.find_first_not_of(' '));
//
//         res_email.erase(res_email.find_last_not_of(' ') + 1);
//         res_email.erase(0, res_email.find_first_not_of(' '));
//
//         res_email = "<" + res_email + ">";
//
        
       beginIndex = endIndex;

       endIndex = record.find(",", endIndex + 1);
       maker = record.substr(beginIndex + 1, endIndex - beginIndex - 1);

       start = maker.find_first_not_of(' ');
       maker = (start == std::string::npos) ? "" : maker.substr(start);

       end = maker.find_last_not_of(' ');
       maker = (end == std::string::npos) ? "" : maker.substr(0, end + 1);

       beginIndex = endIndex;

       endIndex = record.find(",", endIndex + 1);
       auto_condition = record.substr(beginIndex + 1, endIndex - beginIndex - 1);

       start = auto_condition.find_first_not_of(' ');
       auto_condition = (start == std::string::npos) ? "" : auto_condition.substr(start);

       end = auto_condition.find_last_not_of(' ');
       auto_condition = (end == std::string::npos) ? "" : auto_condition.substr(0, end + 1);

       beginIndex = endIndex;
   
       std::string speed = record.substr(beginIndex + 1);

       start = speed.find_first_not_of(' ');
       speed = (start == std::string::npos) ? "" : speed.substr(start);

       end = speed.find_last_not_of(' ');
       speed = (end == std::string::npos) ? "" : speed.substr(0, end + 1);

        
       try{
           max_speed = std::stod(speed);
       }catch (std::exception& ia){
           max_speed = 0;
       }
       if (auto_condition == "n") {
            auto_condition = "new";
       }
       if (auto_condition == "u") {
            auto_condition = "used";
       }
       if (auto_condition == "b") {
            auto_condition = "broken";
       }
    }
    std::string Car::condition() const{
        return auto_condition;
    }
    double Car::topSpeed() const{
        return max_speed;
    }
    void Car::display(std::ostream& out) const{
        out << "| " << std::setw(10) << std::setfill(' ') << maker  << " | ";
        out << std::setw(6) << std::setfill(' ') << std::left << auto_condition << " | ";
        out << std::setw(6) << std::setfill(' ') << std::right << std::fixed << std::setprecision(2) << max_speed << " |" << std::endl;
    }
}
