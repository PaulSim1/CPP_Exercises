#pragma once
#include <iostream>
#include <string>
#include "PlushStore.hpp"

class Kid {

public:
    
    Kid(const std::string &name, const int &money){
        _name = name;
        _money = money;
    }

    std::string get_name(){
        return _name;
    }

    int get_money(){
        return _money;
    }

    void buy_plush(PlushStore plush_store){

    }

private:
    std::string _name;
    int _money;

};