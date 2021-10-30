//
//  Book.cpp
//  laba5
//
//  Created by Анатолий on 10/22/20.
//  Copyright © 2020 Anatoliy. All rights reserved.
//
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Book.h"
namespace sdds{
    Book::Book(){
        author = "";
        book_title ="";
        country_name = "";
        book_year = 0;
        book_price = 0;
        description = "";
    }
    Book::Book(const std::string& strBook){
        std::string str = strBook;

        str.erase(0, str.find(':') + 1);
        author = str.substr(0, str.find(','));

        str.erase(0, str.find(',') + 1);
        book_title =str.substr(0, str.find(','));
          
        str.erase(0, str.find(',') + 1);
        country_name = stoi(str.substr(0, str.find(',')));

        str.erase(0, str.find(',') + 1);
        book_price = stoi(str.substr(0, str.find(',')));
        
        str.erase(0, str.find(',') + 1);
        book_year = stoi(str.substr(0, str.find(',')));

        str.erase(0, str.find(',') + 1);
        description = stoi(str.substr(0, str.find(',')));
        
        author.erase(author.find_last_not_of(' ') + 1);
        author.erase(0, author.find_first_not_of(' '));

        book_title.erase(book_title.find_last_not_of(' ') + 1);
        book_title.erase(0, book_title.find_first_not_of(' '));
          
    }
    const std::string& Book::title() const{
        return book_title;
    }
    const std::string& Book::country() const{
        return country_name;
    }
    const size_t& Book::year() const{
        return book_year;
    }
    double& Book::price(){
        return book_price;
    }
    std::ostream& operator<<(std::ostream& os, const Book& bk){
        os << std::setw(20) << std::setfill(' ') << std::right << bk.author;
        os << std::setw(22) << std::setfill(' ') << std::right << bk.book_title;
        os << std::setw(5) << std::setfill(' ') << std::right << bk.country_name;
        os << std::setw(4) << std::setfill(' ') << std::right << bk.book_year;
        os << std::setw(6) << std::setfill(' ') << std::right << bk.book_price;
        return os;
    }
    
}
