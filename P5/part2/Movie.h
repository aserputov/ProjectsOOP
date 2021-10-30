//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NBB
// Date:           22/10/2020
//==============================================
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
//  Movie.h
//  laba5
//
//  Created by Анатолий on 10/22/20.
//  Copyright © 2020 Anatoliy. All rights reserved.
//

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

#include <iostream>

namespace sdds{
class Movie {
    private:
        std::string movie_title;
        size_t year;
        std::string description;
    public:
        Movie();
        const std::string& title() const;
        Movie(const std::string& strMovie);
        template<typename T>
        void fixSpelling(T spellChecker){
            spellChecker(movie_title);
            spellChecker(description);
        };
        friend std::ostream& operator<<(std::ostream& os, const Movie& mv);
};
}

#endif /* SDDS_MOVIE_H */
