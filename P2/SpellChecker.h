//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NBB
// Date:           22/10/2020
//==============================================
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
//  SpellChecker.h
//  laba5
//
//  Created by Анатолий on 10/22/20.
//  Copyright © 2020 Anatoliy. All rights reserved.
//

#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <iostream>

namespace sdds{
const int SIZE = 5;
class SpellChecker {
    private:
        std::string m_badWords[SIZE];
        std::string m_goodWord[SIZE];
    public:
        SpellChecker(const char* filename);
        void operator()(std::string& text) const;
    
};
}

#endif /* SDDS_SPELLCHECKER_H */
