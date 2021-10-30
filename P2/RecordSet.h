//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NBB
// Date:           27/09/2020
//==============================================//  RecordSet.h
//  Lab2
//
//  Created by Anatoliy on 9/27/20.
//  Copyright © 2020 Anatoliy. All rights reserved.
//

#ifndef RECORDSET_H
#define RECORDSET_H
#include <iostream>
#include <chrono>
#include <cstring>

namespace sdds{
class RecordSet{
    private:
    std::string *n_elements;
    size_t num_stored ;
    public:
        RecordSet();
        RecordSet(const char * event_name);
        RecordSet(const RecordSet& src);
        RecordSet& operator=(const RecordSet& src);
        ~RecordSet();
        size_t size() const;
        std::string getRecord(size_t)const;
        RecordSet(RecordSet&& src)noexcept;
        RecordSet& operator=(RecordSet&& src)noexcept;
};

}

#endif /* RECORDSET_H */
