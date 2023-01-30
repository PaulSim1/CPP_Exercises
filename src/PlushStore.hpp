#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Plush.hpp"

class PlushStore {

public:
    
    PlushStore(const std::string &name){
        _name = name;
    }

    void loan(const int &l){
        _wealth += l;
        _debt += l*1.1;
    }

    int make_plush(const int &price){
        _exp++;
        _wealth -= price;
        return price;
    }

    unsigned int get_experience(){
        return _exp;
    }

    int get_wealth_amount(){
        return _wealth;
    }

    int get_stock_size(){
        return _stock.size();
    }

private:
    std::string _name;
    unsigned int _exp = 0;
    int _wealth = 0;
    int _debt = 0;
    std::vector<Plush> _stock;

};
