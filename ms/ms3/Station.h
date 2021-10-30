// Name: Serputov Anatoliy
// Seneca Student ID: 167389188
// Seneca email: aserputov@myseneca.ca
// Date of completion: 11/11/20
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
//  Station.h
//  ms1
//
//  Created by Анатолий on 11/9/20.
//  Copyright © 2020 Anatoliy. All rights reserved.
//

#ifndef STATION_H
#define STATION_H


class Station{
    private:
        size_t id;
        std::string name;
        std::string description;
        unsigned int serialNumber;
        unsigned int  items_left;
        static size_t m_widthField;
        static int id_generator;
    public:
        Station();
        Station(const std::string& str);
        const std::string& getItemName() const;
        unsigned int getNextSerialNumber();
        unsigned int getQuantity() const;
        void updateQuantity();
        void display(std::ostream& os, bool full) const;
        ~Station();
};

#endif /* SDDS_STATION_H */

