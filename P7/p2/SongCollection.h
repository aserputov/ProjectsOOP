//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NBB
// Date:           27/09/2020
//==============================================//
//  SongCollection.hpp
//  laba7
//
//  Created by Анатолий on 15.11.2020.
//

#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H
#include <iostream>
#include <string>
#include <vector>
#include <list>

namespace sdds {
struct Song{
    std::string artist;
    std::string title;
    std::string album;
    double m_price;
    size_t rel_year;
    size_t song_len;
};

class SongCollection {
    private:
        std::vector<Song> songs;
    public:
        std::string& trim(std::string& str);
        SongCollection(const char* file);
        void display(std::ostream& out) const;
        void sort(std::string);
        void cleanAlbum();
        bool inCollection(std::string) const;
        std::list<Song> getSongsForArtist(std::string) const;
};
std::ostream& operator<<(std::ostream& out, const Song& theSong);

}
#endif /* SDDS_SONGCOLLECTION_H */
