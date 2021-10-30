//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NBB
// Date:           22/10/2020
//==============================================
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
//  Book.h
//  laba5
//
//  Created by Anatoliy on 10/22/20.
//  Copyright © 2020 Anatoliy. All rights reserved.
//
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>

namespace sdds{
class Book {
    private:
        std::string author;
        std::string book_title;
        std::string country_name;
        size_t book_year;
        double book_price;
        std::string description;
    public:
        Book();
        const std::string& title() const;
        const std::string& country() const;
        const size_t& year() const;
        double& price();
        Book(const std::string& strBook);
        friend std::ostream& operator<<(std::ostream& os, const Book& bk);
        template<class T>
        void fixSpelling(T spellChecker){
            spellChecker.operator()(description);
        };
};
}

#endif /* SDDS_BOOK_H */
