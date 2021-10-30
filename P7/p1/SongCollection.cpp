//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NBB
// Date:           27/09/2020
//==============================================//
//  SongCollection.cpp
//  laba7
//
//  Created by Анатолий on 15.11.2020.
//
#include <fstream>
#include <iomanip>
#include <algorithm>
#include "SongCollection.h"

namespace sdds{
    std::string& SongCollection::trim(std::string& str) {
        while (str.length() > 0 && str[0] == ' ')
            str.erase(0, 1);
        while (str.length() > 0 && str[str.length() - 1] == ' ')
            str.erase(str.length() - 1, 1);
        return str;
    }
    SongCollection::SongCollection(const char* file){
        std::ifstream fl(file);
        if (!fl) {
            throw std::string("ERROR: Cannot open file [") + file + ("]. \n");
            return;
        }
        std::string str;
        getline(fl, str);

        while (fl) {
            Song sn;
            trim(sn.title = str.substr(0, 25));
            trim(sn.artist = str.substr(25, 25));
            trim(sn.album = str.substr(50, 25));
            sn.song_len = stoi(str.substr(80, 5));
            sn.m_price = stod(str.substr(85));
            try {
                sn.rel_year = stoi(str.substr(75, 5));
            }catch (...) {
                sn.rel_year = 0;
            }
            songs.push_back(sn);
            getline(fl, str);
        }
    }
    void SongCollection::display(std::ostream& out) const {
        for_each(songs.begin(), songs.end(), [&out](const Song& src){
            out << src << std::endl;
        });
        size_t tl = 0;
        for_each(songs.begin(), songs.end(), [&](const Song& src) {
            tl += src.song_len;
        });
        std::string ttl = "Total Listening Time: ";
        out << "----------------------------------------------------------------------------------------\n";
        ttl += std::to_string(tl / 3600);
        ttl += ":";
        ttl += std::to_string(tl % 3600 / 60);
        ttl += ":";
        ttl += std::to_string(tl % 60);
        
        out << "| " << std::setw(84) << ttl << " |" << std::endl;
    }
    std::ostream& operator<<(std::ostream& out, const Song& theSong) {
        out << "| "  << std::left  << std::setw(20) << theSong.title;
        out << " | " << std::left  << std::setw(15) << theSong.artist;
        out << " | " << std::left  << std::setw(20) << theSong.album;
        out << " | " << std::right << std::setw(6);
                
        if (theSong.rel_year != 0){
            out << theSong.rel_year;
        }else
            out << " ";
        out << " | " ;
        out << theSong.song_len / 60;
        out << ":" << std::setw(2) << std::setfill('0') ;
        out<< theSong.song_len % 60;
        out << " | " << std::fixed << std::setprecision(2) << theSong.m_price << " |" << std::setfill(' ');
                
        return out;
    }
    void SongCollection::sort(std::string fl_name) {
        std::sort(songs.begin(), songs.end(), [=](Song sn, Song sn2){
        if (fl_name == "title") {
                return sn.title < sn2.title;
        }else if (fl_name == "album"){
           return sn.album < sn2.album;
        }else if (fl_name == "length"){
            return sn.song_len < sn2.song_len;
        }
            throw "No matches";
        });
    }
    void SongCollection::cleanAlbum() {
       std::transform(songs.begin(), songs.end(),songs.begin(),[](Song& s) {
            s.album = s.album != "[None]" ? s.album : "";
            return s;
       });
    }
    bool SongCollection::inCollection(std::string art_n) const {
        return std::any_of(songs.begin(), songs.end(), [art_n](const Song& song) {
            return song.artist == std::string(art_n);
        });
    }
    std::list<Song> SongCollection::getSongsForArtist(std::string art_n) const {
        auto count = count_if(songs.begin(), songs.end(), [&art_n](const Song& sn) {
            return sn.artist == art_n;
        });
        std::list<Song> theSongs(count);
        std::copy_if(songs.begin(), songs.end(), theSongs.begin(), [&art_n](const Song& sn) {
            return sn.artist == art_n;
        });
        return theSongs;
    }
}
