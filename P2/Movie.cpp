//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NBB
// Date:           22/10/2020
//==============================================
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments//  Movie.cpp
//  laba5
//
//  Created by Анатолий on 10/22/20.
//  Copyright © 2020 Anatoliy. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <cstring>
#include "Movie.h"
namespace sdds{
    Movie::Movie(){
        movie_title="";
        year = 0;
        description="";
    }
    const std::string& Movie::title() const{
        return movie_title;
    }
    Movie::Movie(const std::string& strMovie){
        std::string str = strMovie;

        movie_title = str.substr(0, str.find(','));

        str.erase(0, str.find(',') + 1);
        year = stoi(str.substr(0, str.find(',')));

        str.erase(0, str.find(',') + 1);
        description = str;

        movie_title.erase(movie_title.find_last_not_of(' ') + 1);
        movie_title.erase(0, movie_title.find_first_not_of(' '));

        description.erase(description.find_last_not_of(' ') + 1);
        description.erase(0, description.find_first_not_of(' '));
    }
    std::ostream& operator<<(std::ostream& os, const Movie& mv){
        os << std::setw(40) << std::setfill(' ') << std::right << mv.movie_title << " | ";
        os << std::setw(4)  << std::setfill(' ') << std::right << mv.year << " | ";
        os << mv.description << std::endl;


      return os;
    }
    
}
