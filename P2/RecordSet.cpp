//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================
// Name:           Anatoliy Serputov
// Student Number: 167389188
// Email:          aserputov@myseneca.ca
// Section:        NBB
// Date:           27/09/2020
//==============================================//
//
//  RecordSet.cpp
//  Lab2
//
//  Created by Anatoliy on 9/27/20.
//  Copyright © 2020 Anatoliy. All rights reserved.
//

#include "RecordSet.h"
#include "RecordSet.h"
#include <iostream>
#include <chrono>
#include <fstream>
#include <cstring>

using namespace std;
namespace sdds{
    RecordSet::RecordSet(){
        n_elements = nullptr;
        num_stored = 0;
    }
    RecordSet::RecordSet(const char * file_name){
        ifstream fin;// defines a file object named fin
        fin.open(file_name); // connects name of the file to fin
        string line;
        size_t num_rec = 0;
            while (getline(fin, line, ' ')){
                num_rec++; // counting the number of records
            }
        fin.close();
            n_elements = new string[num_rec]; // allocating memory
            num_stored = 0;// making counter(number of records) to 0
              fin.open(file_name);
              while (getline(fin, line, ' ')) {
                  n_elements[num_stored] = line;
                  num_stored++; //
              }
              fin.close();
    }
    RecordSet::RecordSet(const RecordSet& src) {
        n_elements = nullptr;
        *this = src; // calls assignment operator
    }
    RecordSet& RecordSet::operator=(const RecordSet& src) {
        if (this != &src) {  // check for self-assignment
            num_stored=src.num_stored;
            delete[] n_elements;
            if(src.n_elements != nullptr){
                n_elements = new string[num_stored];
                    for (size_t i = 0; i < num_stored; i++){
                        n_elements[i] = src.n_elements[i];
                    }
            }else{
                n_elements = nullptr;
            }
        }
        return *this;
    }
    size_t RecordSet::size() const{
        return num_stored;
    }
    string RecordSet::getRecord(size_t index) const{
        if(index < num_stored){
            return n_elements[index];
        }else{
            return "";
        }
    }
    RecordSet::RecordSet(RecordSet&& src)noexcept{
       *this = move(src);
    }
    RecordSet&  RecordSet::operator=(RecordSet&& src)noexcept{
      if (this != &src) {  // check for self-assignment
          n_elements = src.n_elements;
          num_stored = src.num_stored;
          
          src.num_stored = 0;
          src.n_elements = nullptr;
      }
    return *this;
    }
    RecordSet::~RecordSet(){
            delete[] n_elements;
            n_elements = nullptr;
        }
}
