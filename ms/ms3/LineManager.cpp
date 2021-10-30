// Name: Serputov Anatoliy
// Seneca Student ID: 167389188
// Seneca email: aserputov@myseneca.ca
// Date of completion: 23/11/20
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
// In this part I received help from Andrei Batomunkuev
// my classmate with help for a logic in my constructor but
// I changed it with my logic(getline). It was as an idea
// and he helped me to create an extra variable too in the
// header and in the run fucntion.
//  LineManager.cpp
//  ms3
//
//  Created by Анатолий on 23.11.2020.
//

#include <fstream>
#include "LineManager.h"
#include "Utilities.h"

    LineManager::LineManager(const std::string& file_name, std::vector<Workstation*>& obj_add, std::vector<CustomerOrder>& cust_ord){
        std::fstream fl(file_name);
        std::string line;
        while(getline(fl, line)){
            Utilities utl;
            size_t next_pos = 0;
            bool check = true;
        
            std::string station = utl.extractToken(line, next_pos, check);
            std::string next;
            
            if(check){
                next = utl.extractToken(line, next_pos, check);
            }
            for(size_t i = 0; i < obj_add.size(); i++){
                if(station == obj_add[i]->getItemName()){
                    add.push_back(obj_add[i]);
                    for(size_t o = 0; o < obj_add.size(); o++){
                        if(obj_add[o]->getItemName() == next){
                            obj_add[i]->setNextStation(*obj_add[o]);
                        }
                    }
                }
            }
        }
        for (size_t i = 0; i < cust_ord.size(); i++){
            ToBeFilled.push_back(std::move(cust_ord[i]));
        }
        AssemblyLine = obj_add;
        m_cntCustomerOrder = cust_ord.size();
    }

    bool LineManager::run(std::ostream& os){
        static size_t counter = 1;
        if(!ToBeFilled.empty()){
            *(add[0]) += std::move(ToBeFilled.front());
            ToBeFilled.pop_front();
        }
        os << "Line Manager Iteration: " << counter << std::endl;
        for(auto i : AssemblyLine){
            i->runProcess(os);
        }
        for(auto i : add){
            i->moveOrder();
        }
        for(auto i : AssemblyLine){
            CustomerOrder cust_tmp;
            if(i->getIfCompleted(cust_tmp)) {
                Completed.push_back(std::move(cust_tmp));
            }
        }
        counter++;
        return Completed.size() == m_cntCustomerOrder;
    }
    void LineManager::displayCompletedOrders(std::ostream& os) const{
        for(auto& order : Completed){
            order.display(os);
        }
    }
    void LineManager::displayStations() const{
        for(auto station : AssemblyLine){
            station->display(std::cout);
        }
    }
    void LineManager::displayStationsSorted() const{
        for(auto station : add){
            station->display(std::cout);
        }
    }
