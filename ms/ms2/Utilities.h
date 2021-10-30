// Name: Serputov Anatoliy
// Seneca Student ID: 167389188
// Seneca email: aserputov@myseneca.ca
// Date of completion: 11/11/20
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
//  Utilities.h
//  ms1
//
//  Created by Анатолий on 11/9/20.
//  Copyright © 2020 Anatoliy. All rights reserved.
//

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <iostream>

class Utilities{
    private:
        size_t m_widthField = 1;
        static char m_delimiter;
    public:
        void setFieldWidth(size_t newWidth);
        size_t getFieldWidth() const;
        std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
        static void setDelimiter(char newDelimiter);
        static char getDelimiter();
};



#endif /* SDDS_UTILITIES_H */
