//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NBB
// Date:           18/10/2020
//==============================================
//  Restaurant.h
//  laba4
//
//  Created by Anatoliy on 10/14/20.
//  Copyright © 2020 Anatoliy. All rights reserved.
//

#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H

#include "Reservation.h"

namespace sdds{
class Restaurant {
    private:
        Reservation * arr_obj;
        size_t num_reservs;
    public:
        Restaurant();
        Restaurant(Reservation* reservations[], size_t cnt);
        Restaurant(const Restaurant &rs);
        Restaurant(Restaurant &&rs);
        size_t size() const;
    
        ~Restaurant();
        friend std::ostream& operator<<(std::ostream& os, const Restaurant& rs);
    };
}
#endif /* SDDS_RESTAURANT_H */
