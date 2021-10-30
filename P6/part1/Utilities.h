//
//  Utilities.hpp
//  ws6
//
//  Created by Анатолий on 10/29/20.
//  Copyright © 2020 Anatoliy. All rights reserved.
//

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <iostream>
#include "Vehicle.h"
#include "Car.h"

namespace sdds {
    Vehicle* createInstance(std::istream& in);
}

#endif /* SDDS_UTILITIES_H */
