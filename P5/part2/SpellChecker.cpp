//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NBB
// Date:           22/10/2020
//==============================================
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
//  SpellChecker.cpp
//  laba5
//
//  Created by Анатолий on 10/22/20.
//  Copyright © 2020 Anatoliy. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include "SpellChecker.h"
namespace sdds{
    SpellChecker::SpellChecker(const char* filename){
        std::ifstream spellcheck(filename);
        if (!spellcheck) {
            throw "Bad file name!";
        }
        size_t i = 0;
        while (i < SIZE) {
            spellcheck >> m_badWords[i];
            spellcheck >> m_goodWord[i];
            i++;
        }
    }
    void SpellChecker::operator()(std::string& text) const{
         for (size_t i = 0; i < SIZE ; i++) {
             while ((text.find(m_badWords[i])) != std::string::npos) {
                 text.replace(text.find(m_badWords[i]), m_badWords[i].length(), m_goodWord[i]);
             }
         }
    }
       
}

