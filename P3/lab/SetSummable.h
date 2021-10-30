//
//  SetSummable.h
//  laba3
//
//  Created by Анатолий on 10/8/20.
//  Copyright © 2020 Anatoliy. All rights reserved.
//

#ifndef SETSUMMABLE_H
#define SETSUMMABLE_H
#include <cstring>
#include "Set.h"

namespace sdds{
template<typename T ,unsigned int N>
class SetSummable : public Set<T,N> {
    public:
       T accumulate(const std::string& filter) const{
           T accumul;
           for (size_t i = 0; i < this->size(); i++) {
              
           }
           return accumul;
           
        };
};
}
#endif /* SETSUMMABLE_H */
