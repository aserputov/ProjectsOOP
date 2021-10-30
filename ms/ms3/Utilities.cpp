// Name: Serputov Anatoliy
// Seneca Student ID: 167389188
// Seneca email: aserputov@myseneca.ca
// Date of completion: 11/11/20
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
//  Utilities.cpp
//  ms1
//
//  Created by Анатолий on 11/9/20.
//  Copyright © 2020 Anatoliy. All rights reserved.
//

#include "Utilities.h"
#include <iostream>

    char Utilities::m_delimiter;

    void Utilities::setFieldWidth(size_t newWidth){
        m_widthField = newWidth;
    }
    size_t Utilities::getFieldWidth() const{
        return m_widthField;
    }
    std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more){
        size_t end = str.find(m_delimiter, next_pos);
        std::string tk = str.substr(next_pos, end - next_pos);
        if (tk == "") {
            more = false;
            throw"Err";
        }else{
            if(end !=  std::string::npos){
                more = true;
            }else
                more = false;
            next_pos = end + 1;
            if (m_widthField < tk.length())
                m_widthField = tk.length();
        }
        return tk;
    }
    void Utilities::setDelimiter(char newDelimiter){
        m_delimiter = newDelimiter;
    }
    char Utilities::getDelimiter(){
        return m_delimiter;
    }

