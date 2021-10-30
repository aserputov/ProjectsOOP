//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NBB
// Date:           18/10/2020
//==============================================
//  ConfirmationSender.hpp
//  laba4
//
//  Created by Anatoliy on 10/17/20.
//  Copyright © 2020 Anatoliy. All rights reserved.
//
#ifndef  SDDS_CONFIRMATIONSENDER_H
#define  SDDS_CONFIRMATIONSENDER_H

#include "Reservation.h"

namespace sdds{
    class ConfirmationSender{
        private:
            const Reservation** res_arr;
            size_t res_numb;
        public:
            ConfirmationSender();
            ~ConfirmationSender();
            ConfirmationSender& operator+=(const Reservation& res);
            ConfirmationSender& operator-=(const Reservation& res);
            friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& confirm);
            ConfirmationSender(const ConfirmationSender &rs);
            ConfirmationSender(ConfirmationSender &&rs);
    };
}


#endif /*  SDDS_vCONFIRMATIONSENDER_H */
