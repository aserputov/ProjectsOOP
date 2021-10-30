//
//  Utilities.cpp
//  ws6
//
//  Created by Анатолий on 10/29/20.
//  Copyright © 2020 Anatoliy. All rights reserved.
//


#include <cstring>
#include <iostream>
#include <iomanip>
#include "Utilities.h"

namespace sdds {
    Vehicle* createInstance(std::istream& as) {
        char buffer = as.get();
        while (buffer == ' ') {
            buffer = as.get();
        }

        as.putback(buffer);

        if (buffer == 'c' || buffer == 'C') {
            Car* temp2 = new Car(as);
            return temp2;
        }
        else {
            return nullptr;
        }
    }
}
