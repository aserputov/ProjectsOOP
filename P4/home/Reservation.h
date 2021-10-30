//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NBB
// Date:            18/10/2020
//==============================================
//
//  Reservation.h
//  laba4
//
//  Created by Anatoliy on 10/12/20.
//  Copyright © 2020 Anatoliy. All rights reserved.
//

#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H
#include <cstring>
#include <string>
namespace sdds{

class Reservation{
    private:
        std::string res_id;
        std::string res_name;
        std::string res_email;
        size_t res_num_ppl;
        size_t res_day;
        size_t res_hour;
    public:
        Reservation();
        Reservation(const std::string& res);
        friend std::ostream& operator<<(std::ostream& os, const Reservation& res);
    };
}
#endif /* SDDS_RESERVATION_H */
